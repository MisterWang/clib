/*
 * =====================================================================================
 *
 *       Filename:  httprequest.c
 *
 *    Description:  http 请求
 *
 *        Version:  1.0
 *        Created:  2017年09月28日 17时01分43秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <error.h>
#include <errno.h>

#include <fcntl.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 80
/*#define PORT 8182*/
#define SERVER_IP "127.0.0.1"

#define HTTP_DEBUG 1

void http_request(char* host,char* url,int port){
	int sfd;
	struct sockaddr_in addr;
	char buffer[4096],rdbuf[4096],temp[256];

	if((sfd=socket(AF_INET,SOCK_STREAM,0))<0) {printf("create error:%d\n",errno);exit(1);}
	
	printf("host:%s, url:%s,port:%d\n",host,url,port);
	bzero(&addr,sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port=htons(port);
	addr.sin_addr.s_addr = inet_addr(host);
	if(connect(sfd,(struct sockaddr*)&addr,sizeof(addr))<0) {printf("connect error:%d\n",errno);exit(1);}

	sprintf(buffer,"GET %s HTTP1.1\r\n",url);
	sprintf(temp,"Host:%s\r\n",host);
	strcat(buffer,temp);
	strcat(buffer,"Accept:text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8\r\n");
	strcat(buffer,"Connection:keep-alive\r\n");
	strcat(buffer,"User-Agent:Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/61.0.3163.79 Safari/537.36\r\n");
	
	strcat(buffer,"\r\n");
	send(sfd,buffer,sizeof(buffer),0);

	recv(sfd,rdbuf,sizeof(rdbuf),0);
	printf("recv--------------------\n%s\n",rdbuf);
}

#if HTTP_DEBUG
int main()
{
	http_request(SERVER_IP,"/",80);	
	return 0;
}
#endif
