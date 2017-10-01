////
////  daytimetcpcli.cpp
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
//	if(argc != 3)
//		err_quit("usage: daytimetcpcli <hostname/IPPaddress> <service/port#>");
//	
//	int sockfd = Tcp_connect(argv[1], argv[2]);
//	
//	sockaddr_storage ss;
//	socklen_t len = sizeof(ss);
//	Getpeername(sockfd, (SA*)&ss, &len);
//	printf("connected to %s\n", Sock_ntop_host((SA*)&ss, len));
//	
//	char recvline[MAXLINE + 1];
//	ssize_t n = 0;
//	while( (n = Read(sockfd, recvline, MAXLINE)) > 0)
//	{
//		recvline[n] = 0;
//		Fputs(recvline, stdout);
//	}
//	Close(sockfd);
//	
//	return 0;
//}
