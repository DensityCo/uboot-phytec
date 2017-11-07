#include <common.h>
#include <watchdog.h>

static int do_wdt(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[]) {
	int ret = CMD_RET_SUCCESS;

	if (argc < 2 || argc > 2) {
		return CMD_RET_USAGE;
	}

	if (!strcmp(argv[1], "disable")) {
		WATCHDOG_DISABLE();
		printf("wdt disabled\n");
		return ret;
	}

	if (!strcmp(argv[1], "enable")) {
		hw_watchdog_init();
		printf("wdt enabled\n");
		return ret;
	}

	if (!strcmp(argv[1], "reset")) {
		WATCHDOG_RESET();
		printf("wdt reset\n");
		return ret;
	}

	if (!strcmp(argv[1], "test")) {
		/* Lock up the CPU with nothing */
		for (;;) { }
	}

	return ret;
}

U_BOOT_CMD(wdt, CONFIG_SYS_MAXARGS, 1, do_wdt,
	"Watchdog (wtd)",
	"disable - disable the watchdog\n"
	"enable - enable the watchdog\n"
	"reset - feed the watchdog\n"
	"test - make the watchdog fire\n"
);
