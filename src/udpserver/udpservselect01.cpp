//
//  udpservselect01.cpp
//  server
//
//  Created by wangds on 2017/8/26.
//  Copyright © 2017年 Suphinelee. All rights reserved.
//

#include <stdio.h>
#include "../../util/util/unp.h"

static void sig_chld(int);

int main(int argc, char* argv[])
{
	/*		create listen TCP socket		*/
	int listenfd = Socket(AF_INET, SOCK_STREAM, 0);
	sockaddr_in servaddr;
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(SERV_PORT);
	
	const int on = 1;
	Setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
	Bind(listenfd, (SA*)&servaddr, sizeof(servaddr));
	Listen(listenfd, LISTENQ);
	
	/*		create UDP socket		*/
	int udpfd = Socket(AF_INET, SOCK_DGRAM, 0);
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(SERV_PORT);
	
	Bind(udpfd, (SA*)&servaddr, sizeof(servaddr));
	
	sockaddr_in cliaddr;
	bzero(&cliaddr, sizeof(cliaddr));
	pid_t childpid;
	fd_set rset;
	FD_ZERO(&rset);
	FD_SET(listenfd, &rset);
	FD_SET(udpfd, &rset);
	int maxfdp1 = max(listenfd, udpfd) + 1;
	Signal(SIGCHLD, sig_chld);
	while(true)
	{
		int nready = select(maxfdp1, &rset, nullptr, nullptr, nullptr);
		if (nready < 0)
		{
			if(errno == EINTR)	//	处理由sig_chld信号处理函数导致的中断
				continue;
			else
				err_sys("select error");
		}
		
		if(FD_ISSET(listenfd, &rset))
		{
			socklen_t len = sizeof(cliaddr);
			int connfd = Accept(listenfd, (SA*)&cliaddr, &len);
			
			if((childpid = Fork()) == 0)	// child process
			{
				Close(listenfd);			//	close listen socket
				Close(udpfd);				//	close upd socket
				str_echo(connfd);			//	process the request
				exit(0);
			}
			Close(connfd);
		}
		
		if (FD_ISSET(udpfd, &rset))
		{
			socklen_t len = sizeof(cliaddr);
			char msg[MAXLINE];
			ssize_t n = Recvfrom(udpfd, msg, MAXLINE, 0, (SA*)&cliaddr, &len);
			
			Sendto(udpfd, msg, n, 0, (SA*)&cliaddr, len);
		}
	}
	
	
	return 0;
}

void sig_chld(int signo)
{
	int stat;
	pid_t pid;
	while((pid = waitpid(-1, &stat, WNOHANG)) > 0)
		printf("child %d terminate\n", pid);
	return;
}
