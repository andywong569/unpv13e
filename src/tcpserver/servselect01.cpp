////
////  servselect01.cpp
////  server
////
////  Created by Suphinelee on 2017/7/24.
////  Copyright © 2017年 Suphinelee. All rights reserved.
////
//
//#include <stdio.h>
//#include "../../util/util/unp.h"
//
//
//int main(int argc, const char * argv[])
//{
////////////////////////////////////////////////////////////////////////////////////////////////			/*						初始化						*/
//	
//	int listenfd = Socket(AF_INET, SOCK_STREAM, 0);	//	创建监听sock描述符
//	
//	sockaddr_in sin;	//	监听sock地址
//	bzero(&sin, sizeof(sin));
//	sin.sin_family = AF_INET;
//	sin.sin_addr.s_addr = htonl(INADDR_ANY);
//	sin.sin_port = htons(SERV_PORT);
//	
//	Bind(listenfd, (SA*)&sin, sizeof(sin));
//	Listen(listenfd, LISTENQ);
//	
//	sockaddr_in clisin;	//	客户端sock地址
//	socklen_t clilen;	//	客户端sock长度
//	int connfd;			//	客户端连接描述符
//	int client[FD_SETSIZE];		//	客户端连接描述符数组
//	memset(client, -1, FD_SETSIZE);
//	fd_set rset;	//	描述符集
//	FD_ZERO(&rset);
//	FD_SET(listenfd, &rset);
//	int maxfd = listenfd;	//	initialize
//	char buf[MAXLINE];
//	
//	
////////////////////////////////////////////////////////////////////////////////////////////////
//	
//	while(true)
//	{
//		int nready = Select(maxfd + 1, &rset, nullptr, nullptr, nullptr);
//		
//		//	new client connnection
//		if(FD_ISSET(listenfd, &rset))
//		{
//			clilen = sizeof(clisin);
//			connfd = Accept(listenfd, (SA*)&clisin, &clilen);
//			
//			int i = 0;
//			for(; i != FD_SETSIZE; ++i)
//			{
//				if(client[i] < 0)
//				{
//					client[i] = connfd;		//	save descriptor
//					break;
//				}
//			}
//			if(i == FD_SETSIZE)
//				err_quit("too many clients");
//			
//			FD_SET(connfd, &rset);		//	add new descriptor to set
//			maxfd = max(connfd, maxfd);	//	for select
//			
//			if(--nready <= 0)	//	no more readable
//				continue;
//		}
//		
//		//	check all client for data
//		for (int i = 0; i != FD_SETSIZE; ++i)
//		{
//			if(client[i] < 0)
//				continue;
//			
//			if(FD_ISSET(client[i], &rset))
//			{
//				int sockfd = client[i];
//				int nread = 0;
//				if( (nread = Read(sockfd, buf, MAXLINE)) == 0 )	//	connection closed by client
//				{
//					Close(sockfd);
//					FD_CLR(sockfd, &rset);
//					client[i] = -1;
//				}
//				else
//					Writen(sockfd, buf, nread);
//				
//				if(--nready <= 0)	//	no more readable
//					break;
//			}
//			
//		}
//		
//	}
//	
//	return 0;
//}
