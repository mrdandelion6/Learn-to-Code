/*
 * gcc -o stack -g stack.c
 * gcc -S -o stack.s stack.c
 * gdb stack
 * try the following gdb commands:
 * list sumNums
 * break 86
 * run
 * print i
 * step
 * print i
 * info registers
 * display i
 * print &sum
 * print &main
 * x/6w 0xbffff9e0
 * disassemble main
 */


/* 
Memory looks like (1 byte=8 bits at a time) 
Note: This is a 32 bit architecture, so I show
4 bytes in a line. The machine likes to fetch
memory 4 bytes at a time on 4 byte boundaries.
Larger scalars (>1 byte) are 4 byte boundary alligned.

Note: Change in organization of memory from our declarations

      Address   +0     +1     +2     +3       Whats there
      
      00000000
      00000004
      ...
      globals are in this part of memory
      08049698   f      f      f      f
      0804969c   l      l      l      l
      080496a0   i      i      i      i
      080496a4   c      ?      ?      ?
      080496a8   d      d      d      d
      080496ac   d      d      d      d
      080496b0   s      s      ?      ?
      ...
      the stack is down here and grows up
      ...
esp-> bffff990   c      c      c      c  esp 0xbffff9a0 (top of stack is here)
      bffff994   c      c      c      c
      bffff998   c      c      c      c
      bffff99c   c      c      c      c
      bffff9a0   ?      ?      ?      ?
      bffff9a4   ?      ?      ?      ?
      bffff9a8 sum    sum    sum    sum
      bffff9ac   i      i      i      i  (locals on the stack in reverse order)
      bffff9b0   ?      ?      ?      ?
      bffff9b4   ?      ?      ?      ?
ebp-> bffff9b8 sfp    sfp    sfp    sfp  (this is the old frame pointer old ebp)
      bffff9bc ret    ret    ret    ret  (you can see this by x/24w 0xbffff9ac and disassemble main)
      bffff9d0   n      n      n      n
      bffff9d4   m      m      m      m  (args pushed on stack in reverse order)
      
      ...
  
      fffffffc   ?      ?      ?      ?

Symbol     address relative to ebp (see stack.s or disassemble sumNums)
   c              -40(%ebp)
  sum             -16(%ebp)
   i              -12(%ebp)
   n                8(%ebp)
   m               12(%ebp)

*/

#include<stdio.h>

// Global variables, available to the whole program
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
		sum=sum+i;
		i=i+1;
	}
	
	/*
	 * as we did in lecture, modify this so 
	 * that the return address is overwritten with the address of hacked
	c[0]=0xb0;
	c[1]=0x25;
	c[2]=0x33;
	c[3]=0x55;
	*/

	return sum;
}
void f1(int a, int b, int c, int d){

}
void hacked(){
	printf("I've been hacked\n");
}
int main(int argc, char ** argv){
	sumNums(3,7);
	f1(1,2,3,4);
	f1(1,2,3,4);
}
