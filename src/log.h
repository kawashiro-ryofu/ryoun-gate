#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define I 0
#define W 1
#define E 2


void log(int outsign,char outtext[]){
	FILE *log;
	log = fopen("./ry.log","a+");
	char *sign;
	char *color;


	struct tm *clock;
	time_t now;
	time(&now);
	clock = localtime(&now);


	switch(outsign){
		case 0:color = "\033[32;1m";sign = "[i]";break;
		case 1:color = "\033[33;1m";sign = "<!>";break;
		case 2:color = "\033[31;1m";sign ="(x)";break;
	       default:color = "\033[32;1m";sign ="[i]";break;
	
	}
	
	printf("[%d:%d:%d]",clock->tm_hour,clock->tm_min,clock->tm_sec);
	printf("%s%s\033[;0m%s\n",color,sign,outtext);
	fprintf(log,"[%d-%d-%d %d:%d:%d]",clock->tm_year+1900,clock->tm_mon+1,clock->tm_mday,clock->tm_hour,clock->tm_min,clock->tm_sec);
	fprintf(log,"%s%s\n",sign,outtext);
	fclose(log);

}
