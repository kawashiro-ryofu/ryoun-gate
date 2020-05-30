/*
	Copyright 2020 Jeffery_Yu(Kawashiro_Ryofu)
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
#include <netdb.h>
#include "httpf.h"
#include "log.h"

_Bool servOLcheck(char* destination);
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
	
  	log(I,"Bind success!");
	//监听套接字
  	listen(server_socket,40);
	
  	log(I,"Listening...");
	
	while (1){
		struct sockaddr_in clnt_addr;
		int clen = sizeof(clnt_addr);
		
      	//原客户端IP获取，将增加读取报文的方式
	    getpeername(server_socket,(struct sockaddr*)&clnt_addr,&clen);
		log(W,inet_ntoa(clnt_addr.sin_addr));
				
		socklen_t clnt_addr_size = sizeof(clnt_addr);
		
	    //返回给客户端的套接字
      	int clnt_sock = accept(server_socket,(struct sockaddr*)&clnt_addr,&clnt_addr_size);
		log(I,"Accepted...");		
		
		char* getrq = malloc(4096);
		memset(getrq,'\0',4096);
		recv(clnt_sock,getrq,4096,0);

		printf("\n\n\033[34;1m%s\033[;0m\n",getrq);

		//http报文读取
		char* outp;
		
      	if(servOLcheck("git.kawashiros.club")){
			log(I,"Server Connected");
			outp = nhttpg();
		}else{
			log(E,"Server Offline!Returned HTTP 503");
			outp = ehttpg();
		}
		
      	log(I,"Sending...");
      	
		//原先通过write函数的发送方式在此处将会被send函数代替
      	send(clnt_sock,outp,8192,0);
		//关闭套接字
		close(clnt_sock);
	}

	close(server_socket);
}
int main(void){
	
	mainloop();
	
	return 0;
}
_Bool servOLcheck(char* destination){
	struct hostent *server;
	server = gethostbyname(destination);
	if(server == NULL)return 0;
	else return 1;
}
