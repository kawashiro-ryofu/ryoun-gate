/*
	Copyright 2020 Jeffery_Yu
    Licence Under MIT
    
    s.c
    服务程序本体

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include "sentence.h"

//主循环（不知道为什么就做出了这个）
void mainloop(void){
	//创建套接字，绑定地址
	int server_socket = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	struct sockaddr_in local;
	memset(&local,0,sizeof(local));
	local.sin_family = AF_INET;
	local.sin_addr.s_addr = inet_addr("0.0.0.0");
	local.sin_port = htons(80);
	bind(server_socket,(struct sockaddr*)&local,sizeof(local));
	
  	printf("binding success!\n");
	//监听套接字
  	listen(server_socket,40);
	
  	printf("listening...\n");
	
	while (1){
		struct sockaddr_in clnt_addr;
		int clen = sizeof(clnt_addr);
		//客户端IP获取
      	getpeername(server_socket,(struct sockaddr*)&clnt_addr,&clen);
		printf("Cilent IP:%s\n",inet_ntoa(clnt_addr.sin_addr));
		socklen_t clnt_addr_size = sizeof(clnt_addr);
		
      	//返回给客户端的套接字
      	int clnt_sock = accept(server_socket,(struct sockaddr*)&clnt_addr,&clnt_addr_size);
		printf("Accepted...\n");
		//http报文生成
		char *http = "HTTP/1.0 200 OK\r\nServer:AWSL\r\nContent-type:text/html\r\n\r\n";
		char *text = sentence();
		char *outp =(char*) malloc(4096);
		memset(outp,'\0',4096);
		char *html[2]={"\r\n<!doctype html><head><meta charset = \"utf-8\"><title>例行维护中  -Kawashiros</title></head><body style=\"background-color:yellow\"><h1 style=\"font-size:96px\">:(</h1><h3 style=\"font-size:64px\">服务器例行维护中</h3><p>","</p></body>"};
		strcat(outp,http);
		strcat(outp,html[0]);
		strcat(outp,text);
		strcat(outp,html[1]);
	
      	printf("%s",outp);
		printf("Sending...\n");
	    write(clnt_sock,outp,4096);
		//关闭套接字
		close(clnt_sock);
	}

	close(server_socket);
}
int main(void){

		mainloop();
	
		return 0;
}