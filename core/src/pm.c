#include<private/init.h>
#include<sys/types.h>
#include<unistd.h>
#include<errno.h>
#include<stdio.h>

pid_t pm_start(const char *pkg) {
	// TODO: run the package in real
	// Package Manager is not implemented, so just run busybox

	char *path = "/Applications/busybox/Content/busybox";
	char *args[] = { path, "ash" };
	char *env[] = { 
		"HOME=/Users/root",
		"PATH=/Applications/busybox/Content:/System/Applications/penguinburger.system.init/Content"
	};
	
	pid_t status = fork();
			
	switch (status) {
		case 0:
			execve(path, args, env);
			break;

		case -1:
			// TODO: do some error handling
			perror("fork");
			return -1;

		default:
			return status;
	}
}
