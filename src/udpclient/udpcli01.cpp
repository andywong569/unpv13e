//
//  udpcli01.cpp
//  client
//
//  Created by wangds on 2017/8/16.
//  Copyright © 2017年 Suphinelee. All rights reserved.
//

#include <stdio.h>
#include "../../unp/Headers/unp.h"

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		err_quit("usage: udpcli <IPaddress>");
	}

	int sockfd = Socket(AF_INET, SOCK_DGRAM, 0);

	sockaddr_in servaddr;
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(7);
	Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

	dg_cli(stdin, sockfd, (SA*)&servaddr, sizeof(servaddr));

	return 0;
}
