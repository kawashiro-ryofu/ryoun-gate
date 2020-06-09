/*
	Copyright 2020 Jeffery_Yu(Kawashiro_Ryofu)
    Licence Under MIT

    httpf.h
    HTTP报文读取

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sentence.h"
#include "log.h"

char* ehttpg(void);
char* nhttpg(void){
	FILE *fp;
  	//读取当前目录下HTTP报文文件
	fp = fopen("nhttpg.txt","r");
	if(fp == NULL){
		log(E,"Could not read HTTP post file!No Such File Or Directory!");
		exit(0);
	}
	char *a = malloc(65536);
	memset(a,'\0',sizeof(char)*sizeof(a));
	int c =  0;
	do{
		*(a+c) = fgetc(fp);
		c++;
		*(a+(c+1)) = '\0';
	}while(!feof(fp));
	*(a+c-sizeof(char)) = '\0';
	fclose(fp);
	return a;
}

char* ehttpg(void){
  	//出错页
	char *http = "HTTP/1.0 503 Service Unavailable\r\nRetry-After: 180\r\nServer:AWSL\r\nContent-type:text/html\r\n\r\n";
	char *text = randSentence();
	char *outp =(char*) malloc(4096);
	memset(outp,'\0',4096);
	char *html[2]={"\r\n<!doctype html><head><meta charset = \"utf-8\"><title>啊咧咧？  -Kawashiros</title></head><body style=\"background-color:yellow\"><h1 style=\"font-size:96px\">:(</h1><h3 style=\"font-size:64px\">服务器在摸鱼啊……</h3><p>","</p></body>"};
	strcat(outp,http);
	strcat(outp,html[0]);
	strcat(outp,text);
	strcat(outp,html[1]);
	return outp;
}
