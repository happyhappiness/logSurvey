
    leave_suid();		/* Run as non privilegied user */
    if (geteuid() == 0) {
	debug(0, 0, "Squid is not safe to run as root!  If you must\n");
	debug(0, 0, "start Squid as root, then you must configure\n");
	debug(0, 0, "it to run as a non-priveledged user with the\n");
	debug(0, 0, "'cache_effective_user' option in the config file.\n");
	fatal("Don't run Squid as root, set 'cache_effective_user'!");
    }
    if (httpPortNumOverride != 1)
	Config.Port.http = (u_short) httpPortNumOverride;
    if (icpPortNumOverride != 1)
