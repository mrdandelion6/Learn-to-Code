unsigned long get_sp(void){
	__asm__("movl %esp,%eax");
}
int main(int argc, char *argv[]){
	printf("0x%x\n",get_sp());
}
