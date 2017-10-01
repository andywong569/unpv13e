////
////  strcliselect01.cpp
////  client
////
////  Created by Suphinelee on 2017/7/22.
////  Copyright © 2017年 Suphinelee. All rights reserved.
////
//
//
//#include <stdio.h>
//#include <iostream>
//#include "../../util/util/unp.h"
//
//static void str_cli_select01(FILE*, int);
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
//	str_cli_select01(stdin, sockfd);
//
//
//	return 0;
//}
//
//void
//str_cli_select01(FILE *fp, int sockfd)
//{
//	char	sendline[MAXLINE], recvline[MAXLINE];
//	int		maxfdp1;
//	fd_set	rset;
//	
//	FD_ZERO(&rset);
//	while(true)
//	{
//		FD_SET(fileno(fp), &rset);
//		FD_SET(sockfd, &rset);
//		maxfdp1 = max(fileno(fp), sockfd) + 1;
//		Select(maxfdp1, &rset, nullptr, nullptr, nullptr);
//		
//		//	socket is readable
//		if(FD_ISSET(sockfd, &rset))
//		{
//			if (Readline(sockfd, recvline, MAXLINE) == 0)
//				err_quit("str_cli: server terminated prematurely");
//			
//			Fputs(recvline, stdout);
//		}
//		
//		//	input is readable
//		if(FD_ISSET(fileno(fp), &rset))
//		{
//			if(Fgets(sendline, MAXLINE, fp) == NULL)
//				return;
//			Writen(sockfd, sendline, strlen(sendline));
//		}
//	}
//}
