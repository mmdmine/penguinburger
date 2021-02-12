#include<stddef.h>
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<string.h>
#include<sys/reboot.h>
#include<sys/types.h>
#include<private/init.h>
#include<private/signal_handlers.h>
#include<private/pm.h>
#include<private/log.h>
#include<private/power.h>

typedef void (*signal_handler_type)(void);

signal_handler_type handlers[65] = {
	NULL,
	[2] = signal_handler_reboot,
	[12] = signal_handler_poweroff,
};

static void handler(int sig) {
	signal_handler_type handler = handlers[sig];
	if (handler != NULL) {
		handler();
	}
}

int main(int argc, char **args) {
	if (getpid() != 1) {		
		return 1;
	}
	
	printf("Starting Penguinburger %i\n", VERSION);

	struct sigaction sa;
	memset(&sa, 0, sizeof(sa));
	sa.sa_handler = handler;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGCHLD, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	reboot(RB_DISABLE_CAD);

	log_message("Initializing filesystem...");
	if (init_filesystem() != 0) {
		fprintf(stderr, "Error on system initializations\n"); // TODO: log_error()
		power_do(RB_HALT_SYSTEM);
	}

	log_message("Starting shell...");
	pm_start("busybox");

	while (1) {
		pause();
		// TODO
	}
}
