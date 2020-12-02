#define _XOPEN_SOURCE 700

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int 
main(int argc, char *argv[])
{
	const char *fn = "data/d1.txt";
	int fd = open(fn,O_RDWR);
	struct stat st;
	fstat(fd,&st);
	
	char *data = (char*)mmap(NULL,st.st_size,PROT_READ|PROT_WRITE,MAP_PRIVATE,fd,0);
	
	int *num = malloc(sizeof(int) * 1000);
	char *delim = "\n";
	char *token;

	
		token = strtok(data,delim);
		int i = 0;
	do{
		num[i] = atoi(token);
		i++;
		token = strtok(NULL,delim);
	}while(token != NULL);
	
	for(int i1 = 0; i1 < i; i1++){
		
		int num1 = num[i1];

		for(int i2 = 0; i2 < i; i2++){
			int num2 = num[i2];
			if(num1 + num2 == 2020){
				printf("%d\n", num1 * num2);
			}
		}
	}

	for(int i1 = 0; i1 < i; i1++){
		
		int num1 = num[i1];

		for(int i2 = 0; i2 < i; i2++){
			int num2 = num[i2];

			for(int i3 = 0; i3 < i; i3++){
				int num3 = num[i3];
					if((num1 + num2 + num3) == 2020){
						printf("%d\n", num1*num2*num3);
					}
			}
		}
	}

	return 0;
}
