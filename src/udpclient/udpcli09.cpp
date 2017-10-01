////
////  udpcli09.cpp
////  client
////
////  Created by wangds on 2017/8/26.
////  Copyright © 2017年 Suphinelee. All rights reserved.
////
//
//#include <stdio.h>
//#include "../../util/util/unp.h"
//
//int main(int argc, char* argv[])
//{
//	if (argc != 2)
//	{
//		err_quit("usage: udpcli <IPaddress>");
//	}
//	
//	int sockfd = Socket(AF_INET, SOCK_DGRAM, 0);
//	sockaddr_in servaddr;
//	bzero(&servaddr, sizeof(sockaddr_in));
//	servaddr.sin_family = AF_INET;
//	servaddr.sin_port = htons(SERV_PORT);
//	Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
//	
//	Connect(sockfd, (SA*)&servaddr, sizeof(servaddr));
//	
//	sockaddr_in cliaddr;
//	socklen_t len = sizeof(cliaddr);
//	Getsockname(sockfd, (SA*)&cliaddr, &len);
//	printf("local address %s\n", Sock_ntop((SA*)&cliaddr, len));
//	
//	return 0;
//}
