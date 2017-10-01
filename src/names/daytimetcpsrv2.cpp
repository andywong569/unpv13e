////
////  daytimetcpsrv2.cpp
////  names
////
////  Created by wangds on 2017/9/24.
////  Copyright © 2017年 Suphinelee. All rights reserved.
////
//
//#include <stdio.h>
//#include "../../../util/util/unp.h"
//
//
///**
// *	时间获取服务器程序的最终版本
// *	该版本与daytimetcpsrv1相比唯一的改动是对命令行参数的处理，除了服务名或端口号外，
// *	新版本允许用户指定一个主机名或ip地址供服务器捆绑；
// *	以IPv4启动服务器：	daytimetcpsrv2 0.0.0.0 9999
// *	以IPv6启动服务器：	daytimetcpsrv2 0::0 9999
// */
//int main(int argc, char* argv[])
//{
//	int listenfd = -1;
//	if (argc == 2)
//	{
//		listenfd = Tcp_listen(nullptr, argv[1], nullptr);
//	}
//	else if (argc == 3)
//	{
//		listenfd = Tcp_listen(argv[1], argv[2], nullptr);
//	}
//	else
//	{
//		err_quit("usage: daytimetcpsrv2 [ <host> ] <service or port#>");
//	}
//	
//	sockaddr_storage cliaddr;
//	socklen_t len = sizeof(cliaddr);
//	char buff[MAXLINE];
//	while (true)
//	{
//		len = sizeof(cliaddr);
//		int connfd = Accept(listenfd, (SA*)&cliaddr, &len);
//		printf("connection from %s\n", Sock_ntop((SA*)&cliaddr, len));
//		
//		time_t ticks = time(nullptr);
//		snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
//		Write(connfd, buff, strlen(buff));
//		
//		Close(connfd);
//	}
//	
//	return 0;
//}
