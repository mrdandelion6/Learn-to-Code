#include<stdio.h>

/**
 * 1) Use makeShellcode.pl to create a file 'badInput1' such that, when v3 badInput1 is executed, a shell is run.
 * 2) Explain which buffer is overrun and when the call to shellcode takes place. Draw a picture of the stack the instant
 *    the return address is overwritten.
 * 3) As in question 1, except when v3 badInput3 is run, 'whoami' is executed (you will have to modify shellcode).
 * 4) (Challenge!) Modify shellcode so that when v3 badInput4 is run, the stack is modified so that a call to count(100)
 *    takes place. Upon return from this call, the program completes normally.
 */

int count(int i){
	int j;
	for(j=0;j<i;j++)printf("\n%d",j);
}

void hacked(){
	printf("\n I've been hacked\n");
}

int getFile(char *fileName, char *buffer){
	FILE *file; char c; int i=0;

	file=fopen(fileName, "r");
	while(!feof(file)){
		c=fgetc(file);
		// printf("%c", c);	
		buffer[i++]=c;
	}
	fclose(file);
}

int lenFile(char *fileName){
	int len=0;
	char buffer[1024];
	getFile(fileName, buffer);
	while(buffer[len]!='\0' && len<1024){
		len++;
	}
	return len;
}

int main(int argc, char *argv[]) {
	printf("Started\n");
	printf("The length of the file is %d\n",lenFile(argv[1]));
	printf("Finished\n");
}
