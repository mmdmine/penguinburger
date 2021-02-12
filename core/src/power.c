#include<stdio.h>
#include<signal.h> 
#include<time.h>
#include<unistd.h>
#include<sys/reboot.h>
#include<private/power.h>

void power_do(int command) {
	puts("Sending terminate signal to all processes...");
	kill(-1, SIGTERM);
			
	struct timespec ts;
	ts.tv_sec = 3;
	ts.tv_nsec = 0;
	nanosleep(&ts, NULL);

	puts("Sending kill signal to all processes...");	
	kill(-1, SIGKILL);

	puts("Sync...");
	sync();
	
	puts("Invoking reboot...");
	reboot(command);
}

void power_shutdown() {
	power_do(RB_POWER_OFF);
}

void power_reboot() {
	power_do(RB_AUTOBOOT);
}
