#include<sys/mount.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdio.h>
#include<private/init.h>
#include<private/log.h>

#define DIRECTORIES_LENGTH 9
const char *directories[] = {
	"/System",
	"/System/Processes",
	"/System/Devices",
	"/System/Sys",
	"/System/Temp",
	"/System/Variable",
	"/Temp",
	"/Media",
	"/Users",
	"/Users/root"
};

#define MOUNTPOINTS_COUNT 7
const char *sources[] = {
	"proc",
	"sys",
	"dev",
	"run",
	"tmpfs",
	"tmpfs",
	"tmpfs"
};

const char *fstype[] = {
	"proc",
	"sysfs",
	"devtmpfs",
	"tmpfs",
	"tmpfs",
	"tmpfs",
	"tmpfs"
};

const char *target[] = {
	"/System/Processes",
	"/System/Sys",
	"/System/Devices",
	"/System/Variable",
	"/System/Temp",
	"/Temp",
	"/Media"
};

// return 0 on success
// return 2 on errors while creating folder
// return 3 on error while mounting
int init_filesystem(void) {
	for (int i = 0; i < DIRECTORIES_LENGTH; i++) {		
		struct stat sb;
		if (stat(directories[i], &sb) == 0) {
			if (!S_ISDIR(sb.st_mode)) {
				return 2; // TODO: some error handling
			}
		}
		else {
			int status = mkdir(directories[i], 0755);
			if (status != 0) {
				perror("mkdir"); // TODO: some error handling
				return 2;
			}
		}
	}

	for (int i = 0; i < MOUNTPOINTS_COUNT; i++) {
		log_message("Mounting %s...", target[i]);
		
		int status = mount(sources[i], target[i], fstype[i], 0, "");
		if (status != 0) {
			perror("mount"); // TODO: some error handling
			return 3;
		}
	}

	return 0;
}


