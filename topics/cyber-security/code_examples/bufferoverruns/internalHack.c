#include<stdio.h>

void hacked(){
	printf("Hacked\n");
}
void f(){
	char c[1]; // actually don't need this, but ok.
	int *ref;
	int i;
	/*
	 * You can use gdb to find the return address (to main)
	 * on the stack. Change it so that it points
	 * to hacked() instead. The result is that
	 * instead of returning to main, this function
	 * will return to hacked.
	 */

	c[0]='A';
	// for(i=0;i<20;i++)c[i]='A'; // look for 0x41 on the stack

	// What do the following lines do?
	ref=(int *)(c+99);
	printf("%x\n",ref);
	*ref=&hacked;
}
int main(int argc, char ** argv){
	f();
}


