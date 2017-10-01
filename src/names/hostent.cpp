////
////  main.cpp
////  names
////
////  Created by wangds on 2017/9/16.
////  Copyright © 2017年 Suphinelee. All rights reserved.
////
//
//#include <iostream>
//#include "../../../util/util/unp.h"
//
//int main(int argc, char * argv[])
//{
//	// insert code here...
//	char str[INET_ADDRSTRLEN];
//	
//	hostent* hptr;
//	while (--argc > 0)
//	{
//		char* ptr = *++argv;
//		if ((hptr = gethostbyname(ptr)) == nullptr)
//		{
//			err_msg("gethostbyname error for host: %s: %s",
//					ptr, hstrerror(h_errno));
//			continue;
//		}
//		
//		//	print h_name
//		printf("official hostname: %s\n", hptr->h_name);
//		
//		//	print h_aliases
//		for (char** pptr = hptr->h_aliases; *pptr != nullptr; ++pptr)
//		{
//			printf("\talias: %s\n", *pptr);
//		}
//		
//		//	print h_addrtype
//		switch (hptr->h_addrtype)
//		{
//			case AF_INET:
//			{
//				for (char** pptr = hptr->h_addr_list; *pptr != nullptr; ++pptr)
//				{
//					printf("\taddress: %s\n",
//						   Inet_ntop(AF_INET, *pptr, str, sizeof(str)));
//				}
//			}
//				break;
//			default:
//				err_ret("unknown address type");
//				break;
//		}
//	}
//	
//	std::cout << "Hello, World!\n";
//	return 0;
//}
