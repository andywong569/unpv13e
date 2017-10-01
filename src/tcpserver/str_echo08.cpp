////
////  str_echo08.cpp
////  server
////
////  Created by Suphinelee on 2017/7/20.
////  Copyright © 2017年 Suphinelee. All rights reserved.
////
//
//#include <stdio.h>
//#include "../../util/util/unp.h"
//
//static void sig_chld(int signo);
//static void str_echo08(int sockfd);
//
//int main(int argc, const char * argv[])
//{
//	// insert code here...
//	int sockfd = Socket(AF_INET, SOCK_STREAM, 0);
//	
//	sockaddr_in sin;
//	bzero(&sin, sizeof(sin));
//	sin.sin_family = AF_INET;
//	sin.sin_addr.s_addr = htonl(INADDR_ANY);
//	sin.sin_port = htons(SERV_PORT);
//	
//	Bind(sockfd, (SA*)&sin, sizeof(sin));
//	Listen(sockfd, LISTENQ);
//	Signal(SIGCHLD, sig_chld);
//	
//	sockaddr_in clisin;
//	socklen_t clilen;
//	int connfd;
//	pid_t childpid;
//	while(true)
//	{
//		clilen = sizeof(clisin);
//		if((connfd = accept(sockfd, (SA*)&clisin, &clilen)) < 0)
//		{
//			if(errno == EINTR)	//	处理被中断的系统调用
//				continue;
//			else
//				err_sys("accept error");
//		}
//		
//		if((childpid = Fork()) == 0)	//	child process
//		{
//			Close(sockfd);
//			str_echo08(connfd);
//			exit(0);
//		}
//		Close(connfd);
//	}
//	
//	return 0;
//}
//
//void
//sig_chld(int signo)
//{
//	int stat;
//	pid_t pid;
//	while((pid = waitpid(-1, &stat, WNOHANG)) > 0)
//		printf("child %d terminate\n", pid);
//	return;
//}
//
//void
//str_echo08(int sockfd)
//{
//	long arg1, arg2;
//	char line[MAXLINE];
//	for(;;)
//	{
//		if(Readline(sockfd, line, MAXLINE) == 0)
//			return;		//	conn closed by other end
//		
//		if(sscanf(line, "%ld%ld", &arg1, &arg2) == 2)
//			snprintf(line, sizeof(line), "%ld\n", arg1 + arg2);
//		else
//			snprintf(line, sizeof(line), "input error\n");
//		
//		Writen(sockfd, line, strlen(line));
//	}
//}
