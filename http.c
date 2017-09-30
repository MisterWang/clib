/*
 * =====================================================================================
 *
 *       Filename:  http.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2017年09月30日 12时05分03秒
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

#define HTTP_DEBUG_ 1

/**
 * 127.0.0.1/asdf/sdfd
 * www.baidu.com/asdf
 * 127.0.0.1:8080/sdfdsf?fdfd=dfd&dfds=dfd
 *
 */
void parse_url(char* url){
	char* uri,*port;
	uri=strstr(url,"/");
	if(uri){
		port=strstr(url,":");
		printf("url:%s\n",url);
		if(port){
			to_pos(port+1,uri);
			to_pos(url,port);
		}else
			to_pos(url,uri);
		printf("uri:%s\n",uri);
	}
	
}

void to_pos(char* str,char* pos){
	char *temp;
	int len1,len2;
	
	len1=strlen(str);
	len2=strlen(pos);
	
	temp=malloc(len1-len2);
	bzero(temp,len1-len2);
	strncpy(temp,str,len1-len2);

	printf("%s\n",temp);
	free(temp);
}

#if HTTP_DEBUG_ 
int main(){
	parse_url("127.0.0.1:80/asdfd");

	return 0;
}
#endif

