	printf("         Change your configuration file.\n");
	fflush(stdout);		/* print message */
    }
    if (Config.cleanRate < 1)
	Config.cleanRate = 86400 * 365;		/* one year */
    if (Config.Announce.rate < 1) {
	Config.Announce.rate = 86400 * 365;	/* one year */
	Config.Announce.on = 0;
    }
    if (Config.dnsChildren < 0)
