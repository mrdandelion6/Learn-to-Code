#include<stdio.h>

// global variables, available to the whole program
char c;
short s;
int i;
long l;
float f;
double d;

int sumNums(int n, int m){
	int i;
	int sum=0;
	char c[16];
	i=n;
	while(i<m){
		sum += i;
		i=i+1;
	}
	
	/*
	 * modify this so 
	 * that the return address is overwritten with the address of hacked
	c[0]=0xb0;
	c[1]=0x25;
	c[2]=0x33;
	c[3]=0x55;
	*/

	return sum;
}

int mulNums(int n, int m){
	printf("multiplying %d and %d\n", n, m);
	return n*m;
}

void hacked(){
	printf("I've been hacked\n");
}

int main(int argc, char ** argv){
	sumNums(3,7);
	mulNums(8,5);
}