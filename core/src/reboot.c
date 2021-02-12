#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<signal.h>
#include<sys/reboot.h>
#include<private/power.h>


struct reboot_command {
	int command;
	const char *name;	
};

#define REBOOT_COMMANDS_COUNT 7
struct reboot_command reboot_commands[] = {
	{RB_AUTOBOOT, "hard"},
	{RB_HALT_SYSTEM, "halt"},
	{RB_ENABLE_CAD, "enable_cad"},
	{RB_DISABLE_CAD, "disable_cad"},
	{RB_POWER_OFF, "poweroff"},
	{RB_SW_SUSPEND, "suspend"},
	{RB_KEXEC, "kexec"}
};

void print_usage() {
	printf("Usage: Reboot [command]\n");
	printf("Supported Commands: ");
	for (int i = 0; i < REBOOT_COMMANDS_COUNT; i++) {
		printf("%s ", reboot_commands[i].name);
	}
	putchar('\n');
}

void manual_reboot(char *command) {
	short int command_set = -1;
	int reboot_command;
	for (int i = 0; i < REBOOT_COMMANDS_COUNT; i++) {
		if (strcmp(command, reboot_commands[i].name) == 0) {
			command_set = 0;
			reboot_command = reboot_commands[i].command;
			break;
		}
	}

	if (command_set == -1) {
		fprintf(stderr, "Reboot: Invalid command");
		print_usage();
		exit(1);
		return;
	}
	
	if (reboot_command == RB_ENABLE_CAD ||
		reboot_command == RB_DISABLE_CAD) {
		reboot(reboot_command);
		return;
	}
	
	power_do(reboot_command);
}

// Reboot using killing Init

void auto_reboot() {
	if (kill(1, SIGINT) != 0) {
		perror("Reboot");
		exit(1);
	}
}

// Main

int main(int argc, char **args) {
	switch (argc) {
		case 0:
		case 1:
			auto_reboot();
			break;
		case 2:
			if (strcmp(args[1], "help") == 0) {
				print_usage();
				break;
			}

			if (strcmp(args[1], "--help") == 0) {
				print_usage();
				break;
			}

			if (strcmp(args[1], "-h") == 0) {
				print_usage();
				break;
			}

			if (strcmp(args[1], "-?") == 0) {
				print_usage();
				break;
			}
			
			manual_reboot(args[1]);
			break;
		default:
			print_usage();
			break;
	}
	return 0;
}
