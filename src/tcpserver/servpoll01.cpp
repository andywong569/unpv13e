////
////  servpoll01.cpp
////  server
////
////  Created by Suphinelee on 2017/7/26.
////  Copyright © 2017年 Suphinelee. All rights reserved.
////
//
//#include <stdio.h>
//#include "../../util/util/unp.h"
//
//
//int main(int argc, const char * argv[])
//{
//	//////////////////////////////////////////////////////////////////////////////////////////////			/*						初始化						*/
//	
//	int listenfd = Socket(AF_INET, SOCK_STREAM, 0);	//	创建监听sock描述符
//	
//	sockaddr_in sin;	//	监听sock地址
//	bzero(&sin, sizeof(sin));
//	sin.sin_family = AF_INET;
//	//Inet_pton(AF_INET, "192.168.18.5", &sin.sin_addr);
//	sin.sin_addr.s_addr = htonl(INADDR_ANY);
//	sin.sin_port = htons(SERV_PORT);
//	
//	Bind(listenfd, (SA*)&sin, sizeof(sin));
//	Listen(listenfd, LISTENQ);
//	
//	sockaddr_in clisin;	//	客户端sock地址
//	socklen_t clilen;	//	客户端sock长度
//	int connfd;			//	客户端连接描述符
//	pollfd client[OPEN_MAX];		//	pollfd数组
//	client[0].fd = listenfd;
//	client[0].events = POLLRDNORM;
//	memset(client + 1, -1, OPEN_MAX - 1);	// -1 indicates available entry
//	int maxi = 0;	//	max index into client[] array
//	char buf[MAXLINE];
//	
//	
//	//////////////////////////////////////////////////////////////////////////////////////////////
//	
//	while(true)
//	{
//		int nready = Poll(client, maxi + 1, INFTIM);
//		
//		//	new client connnection
//		if(client[0].revents & POLLRDNORM)
//		{
//			clilen = sizeof(clisin);
//			connfd = Accept(listenfd, (SA*)&clisin, &clilen);
//			
//			int i = 1;
//			for(; i != OPEN_MAX; ++i)
//			{
//				if(client[i].fd < 0)
//				{
//					client[i].fd = connfd;		//	save descriptor
//					client[i].events = POLLRDNORM;
//					break;
//				}
//			}
//			if(i == OPEN_MAX)
//				err_quit("too many clients");
//			
//			maxi = max(maxi, i);	//	max index in client[] array
//			
//			if(--nready <= 0)	//	no more readable
//				continue;
//		}
//		
//		//	check all client for data
//		for (int i = 1; i <= maxi; ++i)
//		{
//			if(client[i].fd < 0)
//				continue;
//			
//			if(client[i].revents & (POLLRDNORM | POLLERR))
//			{
//				int sockfd = client[i].fd;
//				int nread = 0;
//				if( (nread = read(sockfd, buf, MAXLINE)) < 0 )
//				{
//					if(errno == ECONNRESET)		// connection reset by client
//					{
//						Close(sockfd);
//						client[i].fd = -1;
//					}
//					else
//						err_sys("read error");
//				}
//				else if(nread == 0)		//	connection closed by client
//				{
//					Close(sockfd);
//					client[i].fd = -1;
//				}
//				else
//					Writen(sockfd, buf, nread);
//				
//				if(--nready <= 0)	//	no more readable
//					break;
//			}
//		}
//		
//	}
//	
//	return 0;
//}
