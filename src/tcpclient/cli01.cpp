//
//  main.cpp
//  client
//
//  Created by Suphinelee on 2017/7/12.
//  Copyright © 2017年 Suphinelee. All rights reserved.
//

#include <iostream>
#include "../../unp/Headers/unp.h"

int main(int argc, const char * argv[])
{
	// insert code here...
	if(argc != 2)
		err_quit("usage: client <ipaddress>");
		
	int sockfd = Socket(AF_INET, SOCK_STREAM, 0);
	
	sockaddr_in sin;
	bzero(&sin, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(SERV_PORT);
	Inet_pton(AF_INET, argv[1], &sin.sin_addr);
	
	Connect(sockfd, (SA*)&sin, sizeof(sin));
	sockaddr_in locsin;
	locsin.sin_family = AF_INET;
	bzero(&locsin, sizeof(locsin));
	socklen_t locsinLen = sizeof(locsin);
	Getsockname(sockfd, (SA*)&locsin, &locsinLen);
	
	char szName[MAXLINE];
	err_msg("%s:%d", Inet_ntop(AF_INET, &locsin, szName, INET_ADDRSTRLEN), ntohs(locsin.sin_port));
	
	str_cli(stdin, sockfd);
	
	
	return 0;
}
