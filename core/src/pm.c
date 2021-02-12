#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<sys/types.h>
#include<private/init.h>

pid_t pm_start(const char *pkg) {
	// TODO: Implement a library for using PackageManager
	
	char *path = "/System/Applications/penguinburger.system.pm/Content/PackageManager";
	char *args[] = { path, "run", "penguinburger.shell" };
	char *env[] = { 
		"HOME=/Users/root",
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
