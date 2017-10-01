////
////  udpcliconnect.cpp
////  client
////	调用connect的udp客户端程序
////  Created by wangds on 2017/8/19.
////  Copyright © 2017年 Suphinelee. All rights reserved.
////
//
//#include <stdio.h>
//#include "../../util/util/unp.h"
//
//static void dg_cli2(FILE *fp, int sockfd, const SA *pservaddr, socklen_t servlen);
//
//int main(int argc, char* argv[])
//{
//	if (argc != 2)
//	{
//		err_quit("usage: udpcli <IPaddress>");
//	}
//	
//	int sockfd = Socket(AF_INET, SOCK_DGRAM, 0);
//	
//	sockaddr_in servaddr;
//	bzero(&servaddr, sizeof(servaddr));
//	servaddr.sin_family = AF_INET;
//	servaddr.sin_port = htons(SERV_PORT);
//	Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
//	
//	dg_cli2(stdin, sockfd, (SA*)&servaddr, sizeof(servaddr));
//	
//	return 0;
//}
//
//void
//dg_cli2(FILE *fp, int sockfd, const SA *pservaddr, socklen_t servlen)
//{
//	int	n;
//	char	sendline[MAXLINE], recvline[MAXLINE + 1];
//	
//	Connect(sockfd, pservaddr, servlen);
//	
//	while (Fgets(sendline, MAXLINE, fp) != NULL)
//	{
//		Write(sockfd, sendline, strlen(sendline));
//		
//		n = Read(sockfd, recvline, MAXLINE);
//		
//		recvline[n] = 0;	/* null terminate */
//		Fputs(recvline, stdout);
//	}
//}
