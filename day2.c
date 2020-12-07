#define _XOPEN_SOURCE 700

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int
CheckPass(char* min, char* max, char c, char *pass){
	int count = 0;
	int i = 0;
	while(pass[i]){
		if(pass[i] == c){
			count++;
		}
		i++;
	}

	if(count >= atoi(min) && count <= atoi(max)){
		return 1;
	}else{
		return 0;
	}
}

int
CheckPassTwo(char *min, char* max, char c, char *pass){
	if((pass[atoi(min)-1] == c) ^ (pass[atoi(max)-1] == c)){
		return 1;
	}else{
		return 0;
	}
}

int
main(int argc, char *argv[])
{
        const char *fn = "data/d2.txt";

        int fd = open(fn,O_RDWR);
        struct stat st;
        fstat(fd,&st);

        char *data = (char*)mmap(NULL,st.st_size,PROT_READ|PROT_WRITE,MAP_PRIVATE,fd,0);

	char* da = "-";
	char* sp = " ";
	char* nl = "\n";
	char* co = ":";

	int fpol = 0;
	int spol = 0;

	char *min = malloc(sizeof(char)*10);
	char *max = malloc(sizeof(char)*10);
	char *c = malloc(sizeof(char)*10);
	char *pass = malloc(sizeof(char)*100);
	

		min = strtok(data,da);
		max = strtok(NULL,sp);
		c = strtok(NULL,co);
		pass = strtok(NULL,nl);

	while(min){
		pass++;
		fpol += CheckPass(min,max,*c,pass);
		spol += CheckPassTwo(min,max,*c,pass);
		pass--;
		min = strtok(NULL,da);
		max = strtok(NULL,sp);
		c = strtok(NULL,co);
		pass = strtok(NULL,nl);
	}

	printf("first policy: %d, second policy: %d\n",fpol,spol);

	return 0;
}
