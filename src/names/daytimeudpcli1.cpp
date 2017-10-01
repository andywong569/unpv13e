////
////  daytimeudpcli1.cpp
////  names
////
////  Created by wangds on 2017/9/26.
////  Copyright © 2017年 Suphinelee. All rights reserved.
////
//
//#include <stdio.h>
//#include "../../../util/util/unp.h"
//
//int main(int argc, char** argv)
//{
//	if (argc != 3)
//	{
//		err_quit("usage: daytimeudpcli1 <hostname/IPaddress> <service/port#>");
//	}
//	
//	sockaddr* sa = nullptr;
//	socklen_t len = -1;
//	int sockfd = Udp_client(argv[1], argv[2], (SA**)&sa, &len);
//	
//	printf("sending to %s\n", Sock_ntop_host((SA*)sa, len));
//	Sendto(sockfd, "", 1, 0, (SA*)sa, len);
//	
//	char recvline[MAXLINE + 1];
//	ssize_t n = Recvfrom(sockfd, recvline, MAXLINE, 0, nullptr, nullptr);
//	recvline[n] = '\0';
//	Fputs(recvline, stdout);
//	
//	return 0;
//}
