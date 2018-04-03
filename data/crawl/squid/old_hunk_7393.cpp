    parseConfigFile(ConfigFile);

    leave_suid();		/* Run as non privilegied user */

    if (httpPortNumOverride != 1)
	Config.Port.http = (u_short) httpPortNumOverride;