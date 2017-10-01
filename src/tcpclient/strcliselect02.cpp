////
////  strcliselect02.cpp
////  client
////
////  Created by Suphinelee on 2017/7/23.
////  Copyright © 2017年 Suphinelee. All rights reserved.
////
//
//
//#include <stdio.h>
//#include <iostream>
//#include "../../util/util/unp.h"
//
//static void str_cli_select02(FILE*, int);
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
//	str_cli_select02(stdin, sockfd);
//	
//	
//	return 0;
//}
//
//void
//str_cli_select02(FILE *fp, int sockfd)
//{
//	char	buf[MAXLINE];
//	fd_set	rset;
//	int		stdineof = 0;
//	
//	
//	FD_ZERO(&rset);
//	while(true)
//	{
//		if(stdineof == 0)
//			FD_SET(fileno(fp), &rset);
//		FD_SET(sockfd, &rset);
//		int maxfdp1 = max(fileno(fp), sockfd) + 1;
//		Select(maxfdp1, &rset, nullptr, nullptr, nullptr);
//		
//		//	socket is readable
//		if(FD_ISSET(sockfd, &rset))
//		{
//			int n = 0;
//			if((n = Read(sockfd, buf, MAXLINE)) == 0)
//			{
//				if(stdineof == 1)
//					return;		//	normal termination
//				else
//					err_quit("str_cli: server terminated prematurely");
//			}
//			
//			Write(fileno(stdout), buf, n);
//		}
//		
//		//	input is readable
//		if(FD_ISSET(fileno(fp), &rset))
//		{
//			int n = 0;
//			if(	(n = Read(fileno(fp), buf, MAXLINE)) == 0 )
//			{
//				stdineof = 1;
//				Shutdown(sockfd, SHUT_WR);	//	send FIN
//				FD_CLR(sockfd, &rset);
//				continue;
//			}
//			Writen(sockfd, buf, n);
//		}
//	}
//}
