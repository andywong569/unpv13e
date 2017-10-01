////
////  daytimetcpsrv1.cpp
////  names
////
////  Created by wangds on 2017/9/23.
////  Copyright © 2017年 Suphinelee. All rights reserved.
////
//
//#include <stdio.h>
//#include "../../../util/util/unp.h"
//
//int main(int argc, char* argv[])
//{
//	if(argc != 2)
//		err_quit("usage: daytimetcpsrv1 <service or port#>");
//	
//	/*
//	 *	此程序存在一个小问题：tcp_listen的第一个参数是一个空指针，而且tcp_listen内部指定的地址族为AF_UNSPEC，两者结合可能导致getaddrinfo返回非期望地址族的套接字地址结构;
//	 *	举例来说，在双栈主机上返回的第一个套接字地址结构将是ipv6的，但是我们可能希望该服务器仅仅处理ipv4；
//	 *	客户程序没有这样的问题，因为客户总得指定一个ip地址或主机名；
//	 */
//	int listenfd = Tcp_listen(nullptr, argv[1], nullptr);
//	
//	sockaddr_storage cliaddr;
//	socklen_t len = 0;
//	for(;;)
//	{
//		len = sizeof(cliaddr);
//		int connfd = Accept(listenfd, (SA*)&cliaddr, &len);
//		printf("connection from %s\n", Sock_ntop((SA*)&cliaddr, len));
//		
//		time_t ticks = time(nullptr);
//		char buff[MAXLINE];
//		snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
//		Write(connfd, buff, strlen(buff));
//		
//		Close(connfd);
//	}
//	
//	return 0;
//}
