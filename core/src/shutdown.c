#include<stdio.h>
#include<sys/types.h>
#include<signal.h>

int main(int argc, char **args) {
	if (kill(1, SIGUSR2) != 0) {
		perror("Shutdown");
		return 1;
	}
	return 0;
}
