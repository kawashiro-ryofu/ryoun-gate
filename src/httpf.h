#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sentence.h"

char* ehttpg(void);
char* nhttpg(void){
	FILE *fp;
	fp = fopen("nhttpg.txt","r");
	if(fp == NULL)exit(0);
	char *a = malloc(65536);
	memset(a,'\0',sizeof(char)*sizeof(a));
	int c =  0;
	do{
		*(a+c) = fgetc(fp);
		c++;
		*(a+(c+1)) = '\0';
	}while(!feof(fp));
	*(a+c-1) = '\0';
	fclose(fp);
	return a;
}

char* ehttpg(void){
	char *http = "HTTP/1.0 200 OK\r\nServer:AWSL\r\nContent-type:text/html\r\n\r\n";
	char *text = randSentence();
	char *outp =(char*) malloc(4096);
	memset(outp,'\0',4096);
	char *html[2]={"\r\n<!doctype html><head><meta charset = \"utf-8\"><title>例行维护中  -Kawashiros</title></head><body style=\"background-color:yellow\"><h1 style=\"font-size:96px\">:(</h1><h3 style=\"font-size:64px\">服务器例行维护中</h3><p>","</p></body>"};
	strcat(outp,http);
	strcat(outp,html[0]);
	strcat(outp,text);
	strcat(outp,html[1]);
	return outp;
}
