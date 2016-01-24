#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int signal_handler(int);

int main(){
	signal(SIGSEGV, signal_handler);

	int *x = 1000;
	*x = 10;

	asm("block_depois_do_erro:");
	while(1){
		sleep(1);
		puts("Loop...");
	}

	return 0;
}

int signal_handler(int signum){
	puts("Sinal \"Falha de segmento de nucleo\" ativado");

	asm("jmp block_depois_do_erro");
}
