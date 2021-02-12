#include<private/log.h>
#include<private/signal_handlers.h>
#include<private/power.h>

void signal_handler_reboot() {
	log_message("Reboot System");
	power_reboot();
}

void signal_handler_poweroff() {
	log_message("Shutdown System");
	power_shutdown();
}
