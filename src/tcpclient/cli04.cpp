////
////  main.cpp
////  client
////
////  Created by Suphinelee on 2017/7/12.
////  Copyright © 2017年 Suphinelee. All rights reserved.
////
//
//#include <iostream>
//#include "../../util/util/unp.h"
//
//const int CLI_NUM = 5;
//
//int main(int argc, const char * argv[]) {
//	// insert code here...
//	if(argc != 2)
//		err_quit("usage: client <ipaddress>");
//	
//	int sockfd[CLI_NUM];
//	sockaddr_in sin;
//	for(int i = 0; i != CLI_NUM; ++i)
//	{
//		sockfd[i] = Socket(AF_INET, SOCK_STREAM, 0);
//		
//		bzero(&sin, sizeof(sin));
//		sin.sin_family = AF_INET;
//		sin.sin_port = htons(SERV_PORT);
//		Inet_pton(AF_INET, argv[1], &sin.sin_addr);
//		
//		Connect(sockfd[i], (SA*)&sin, sizeof(sin));
//	}
//	
//	str_cli(stdin, sockfd[0]);
//	
//	return 0;
//}
