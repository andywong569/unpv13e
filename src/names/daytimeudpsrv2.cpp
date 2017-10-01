//
//  daytimeudpsrv2.cpp
//  names
//
//  Created by wangds on 2017/9/26.
//  Copyright © 2017年 Suphinelee. All rights reserved.
//

#include <stdio.h>
#include "../../../util/util/unp.h"


int main(int argc, char** argv)
{
	int sockfd = -1;
	if(argc == 2)
	{
		sockfd = Udp_server(nullptr, argv[1], nullptr);
	}
	else if(argc == 3)
	{
		sockfd = Udp_server(argv[1], argv[2], nullptr);
	}
	else
	{
		err_quit("usage: daytimeudpsrv2 [ <host> ] <service or port#>");
	}
	
	char buff[MAXLINE];
	sockaddr_storage sa;
	socklen_t len = sizeof(sa);
	while (true)
	{
		len = sizeof(sa);
		ssize_t n = Recvfrom(sockfd, buff, MAXLINE, 0, (SA*)&sa, &len);
		printf("datagram from %s\n", Sock_ntop((SA*)&sa, len));
		
		time_t ticks = time(nullptr);
		snprintf(buff, MAXLINE, "%.24s\r\n", ctime(&ticks));
		Sendto(sockfd, buff, strlen(buff), 0, (SA*)&sa, len);
	}
	return 0;
}
