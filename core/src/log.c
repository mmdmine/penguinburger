#include <private/init.h>
#include <stdio.h>
#include <stdarg.h>

// TODO: Add log_verbose, log_warning, and log_error
// TODO: Use colors
// TODO: Style messages

void log_message(const char *format, ...) {
	fputs("Init: ", stdout);
	va_list ap;
	va_start(ap, format);
	vprintf(format, ap); // TODO: add timestamp, save log
	va_end(ap);

	putchar('\n');
	fflush(stdout);
}
