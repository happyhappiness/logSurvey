	printf("         Change your configuration file.\n");
	fflush(stdout);		/* print message */
    }
    if (Config.Announce.period < 1) {
	Config.Announce.period = 86400 * 365;	/* one year */
	Config.Announce.on = 0;
    }
    if (Config.dnsChildren < 0)
