/* include sockfd_to_family */
#include    "../../include/unp.h"

//	返回sockfd的协议族，失败为-1
int
sockfd_to_family(int sockfd)
{
	struct sockaddr_storage ss;
	socklen_t	len;

	len = sizeof(ss);
	if (getsockname(sockfd, (SA *) &ss, &len) < 0)
		return(-1);
	return(ss.ss_family);
}
/* end sockfd_to_family */

int
Sockfd_to_family(int sockfd)
{
	int		rc;

	if ( (rc = sockfd_to_family(sockfd)) < 0)
		err_sys("sockfd_to_family error");

	return(rc);
}
