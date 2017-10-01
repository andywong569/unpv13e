////
////  udpserv01.cpp
////  server
////
////  Created by wangds on 2017/8/16.
////  Copyright © 2017年 Suphinelee. All rights reserved.
////
//
//#include <stdio.h>
//#include "../../util/util/unp.h"
//
//
//int main()
//{
//	int sockfd = Socket(AF_INET, SOCK_DGRAM, 0);
//	
//	sockaddr_in servaddr;
//	bzero(&servaddr, sizeof(servaddr));
//	servaddr.sin_family = AF_INET;
//	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");// htonl(INADDR_ANY);
//	servaddr.sin_port = htons(SERV_PORT);
//	
//	Bind(sockfd, (SA*)&servaddr, sizeof(servaddr));
//	
//	sockaddr_in cliaddr;
//	dg_echo(sockfd, (SA*)&cliaddr, sizeof(cliaddr));
//	
//	return 0;
//}
