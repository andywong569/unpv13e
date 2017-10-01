////
////  udpcli02.cpp
////  client
////	验证返回的套接字地址的dg_cli函数版本
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
//	SA* preply_addr = (SA*)Malloc(servlen);
//	while (Fgets(sendline, MAXLINE, fp) != NULL)
//	{
//		Sendto(sockfd, sendline, strlen(sendline), 0, pservaddr, servlen);
//		
//		socklen_t len = servlen;
//		n = Recvfrom(sockfd, recvline, MAXLINE, 0, preply_addr, &len);
//		if(len != servlen || memcmp(pservaddr, preply_addr, len) != 0)
//		{
//			printf("reply from %s (ignored)\n", Sock_ntop(preply_addr, len));
//			continue;
//		}
//		
//		recvline[n] = 0;	/* null terminate */
//		Fputs(recvline, stdout);
//	}
//}
