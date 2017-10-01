//
//  main.cpp
//  server
//
//  Created by Suphinelee on 2017/7/12.
//  Copyright © 2017年 Suphinelee. All rights reserved.
//

#include <iostream>
#include "../../include/unp.h"

static void sig_chld(int signo);

int main(int argc, const char * argv[])
{
	// insert code here...
	int sockfd = Socket(AF_INET, SOCK_STREAM, 0);

	sockaddr_in sin;
	bzero(&sin, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	sin.sin_port = htons(SERV_PORT);

	Bind(sockfd, (SA*)&sin, sizeof(sin));
	Listen(sockfd, LISTENQ);
	Signal(SIGCHLD, sig_chld);

	sockaddr_in clisin;
	socklen_t clilen;
	int connfd;
	pid_t childpid;
	while(true)
	{
		clilen = sizeof(clisin);
		if((connfd = accept(sockfd, (SA*)&clisin, &clilen)) < 0)
		{
			if(errno == EINTR)	//	处理被中断的系统调用
				continue;
			else
				err_sys("accept error");
		}

		if((childpid = Fork()) == 0)	//	child process
		{
			Close(sockfd);
			str_echo(connfd);
			exit(0);
		}
		Close(connfd);
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
