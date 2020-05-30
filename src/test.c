#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void format(char input[]);
int main(){
	FILE *htdoc;
	htdoc = fopen("httprq","r");

	if(htdoc == NULL){
		return 0;
	}
	
	char* httpfile[512];
	int c = 0;
	
	while(1){
		httpfile[c] = fgets(httpfile[c],1024,htdoc);
		c++;
	}
	

	fclose(htdoc);
	return 0;
}
