////
////  daytimetcpcli1.cpp
////  names
////
////  Created by wangds on 2017/9/16.
////  Copyright © 2017年 Suphinelee. All rights reserved.
////
//
//#include <stdio.h>
//#include "../../../util/util/unp.h"
//
//int main(int argc, char* argv[])
//{
//	if(argc != 3)
//		err_quit("usage: daytimetcpcli1 <hostname> <service>");
//	
//	hostent* hp = nullptr;
//	in_addr** pptr = nullptr;
//	in_addr inetaddr;
//	in_addr* inetaddrp[2]{ nullptr };
//	if((hp = gethostbyname(argv[1])) == nullptr)
//	{
//		if(inet_aton(argv[1], &inetaddr) == 0)
//		{
//			err_quit("hostname error for %s: %s",
//					 argv[1], hstrerror(h_errno));
//		}
//		else
//		{
//			inetaddrp[0] = &inetaddr;
//			pptr = inetaddrp;
//		}
//	}
//	else
//	{
//		pptr = (in_addr**)hp->h_addr_list;
//	}
//	
//	servent* sp = nullptr;
//	if((sp = getservbyname(argv[2], "tcp")) == nullptr)
//	{
//		err_quit("getservbyname error for %s: %s",
//				 argv[2], hstrerror(h_errno));
//	}
//	
//	int sockfd = -1;
//	sockaddr_in servaddr;
//	for(; *pptr != nullptr; ++pptr)
//	{
//		sockfd = Socket(AF_INET, SOCK_STREAM, 0);
//		
//		bzero(&servaddr, sizeof(servaddr));
//		servaddr.sin_family = AF_INET;
//		servaddr.sin_port = sp->s_port;
//		memcpy(&servaddr.sin_addr, *pptr, sizeof(in_addr));
//		printf("trying %s\n", Sock_ntop((SA*)&servaddr, sizeof(servaddr)));
//		
//		if(connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) == 0)
//		{
//			break;	// success
//		}
//		err_ret("connect error");
//		Close(sockfd);
//	}
//	
//	if(*pptr == nullptr)
//	{
//		err_quit("unable to connect");
//	}
//	
//	char recvline[MAXLINE + 1]{ 0 };
//	ssize_t n = -1;
//	while((n = Read(sockfd, recvline, MAXLINE)) > 0)
//	{
//		Fputs(recvline, stdout);
//	}
//	
//	return 0;
//}
