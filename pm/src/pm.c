#include<stdio.h>
#include<string.h>

void print_usage() {
	printf("Usage: PackageManager run <package> [command]\
\t\t info <package>\
\t\t list\
\t\t install <file>\
\t\t uninstall <package>\n");
}

int main(int argc, char **args) {
	if (argc <= 1) {
		fprintf(stderr, "No command specified.\n");
		print_usage();
		return 1;
	}

	if (strcmp(args[1], "help") == 0 ||
		strcmp(args[1], "--help") == 0 ||
		strcmp(args[1], "-help") == 0 ||
		strcmp(args[1], "-h") == 0 ||
		strcmp(args[1], "-?") == 0) {
		print_usage();
		return 0;
	}

	if (strcmp(args[1], "list") == 0) {
		printf("PackageManager-list is not implemented\n");
		return 2;
	}

	if (strcmp(args[1], "run") == 0) {
		printf("PackageManager-run is not implemented\n");
		return 2;
	}

	if (strcmp(args[1], "install") == 0) {
		printf("PackageManager-install is not implemented\n");
		return 0;
	}

	if (strcmp(args[1], "uninstall") == 0) {
		printf("PackageManager-uninstall is not implemented\n");
		return 0;
	}

	fprintf(stderr, "Invalid command: %s\n", args[1]);
	print_usage();
	return 1;
}
