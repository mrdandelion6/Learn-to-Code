#include<stdio.h>

void concat(int numFiles, char *fileNames[]){
	int len=0;
	char buffer[1020];
	FILE *file; 
	char c; 
	int i=0, fileIndex=0;
	for(fileIndex=0;fileIndex<numFiles;fileIndex++){
		printf("%d %s\n", numFiles, fileNames[fileIndex]);
		file=fopen(fileNames[fileIndex], "r");
		while(!feof(file) && len<1020){
			c=fgetc(file);
			buffer[i++]=c;
			len++;
		}
		buffer[i]='\0';
		fclose(file);
	}
	printf("%s\n", buffer);
}

int main(int argc, char *argv[]) {
	printf("\n%d", argc);
	printf("Started\n");
	concat(argc-1, &argv[1]);
	printf("Finished\n");
}
