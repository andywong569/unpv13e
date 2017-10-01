////
////  str_cli11.cpp
////  client
////
////  Created by Suphinelee on 2017/7/19.
////  Copyright © 2017年 Suphinelee. All rights reserved.
////
//
//#include <stdio.h>
//#include <iostream>
//#include "../../util/util/unp.h"
//
//static void str_cli11(FILE*, int);
//
//int main(int argc, const char * argv[])
//{
//	// insert code here...
//	if(argc != 2)
//		err_quit("usage: client <ipaddress>");
//	
//	int sockfd = Socket(AF_INET, SOCK_STREAM, 0);
//	
//	sockaddr_in sin;
//	bzero(&sin, sizeof(sin));
//	sin.sin_family = AF_INET;
//	sin.sin_port = htons(SERV_PORT);
//	Inet_pton(AF_INET, argv[1], &sin.sin_addr);
//	
//	Connect(sockfd, (SA*)&sin, sizeof(sin));
//	
//	str_cli11(stdin, sockfd);
//	
//	
//	return 0;
//}
//
//void
//str_cli11(FILE *fp, int sockfd)
//{
//	char	sendline[MAXLINE], recvline[MAXLINE];
//	
//	while (Fgets(sendline, MAXLINE, fp) != NULL)
//	{
//		
//		Writen(sockfd, sendline, 1);
//		sleep(1);
//		
//		Writen(sockfd, sendline + 1, strlen(sendline) - 1);
//		
//		if (Readline(sockfd, recvline, MAXLINE) == 0)
//			err_quit("str_cli: server terminated prematurely");
//		
//		Fputs(recvline, stdout);
//	}
//}
