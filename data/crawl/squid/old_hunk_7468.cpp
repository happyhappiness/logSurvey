	Config.cleanRate = 86400 * 365;		/* one year */
    if (Config.Announce.rate < 1)
	Config.Announce.rate = 86400 * 365;	/* one year */
    if (Config.dnsChildren < 1) {
	printf("WARNING: dns_children was set to a bad value: %d\n",
	    Config.dnsChildren);
	Config.dnsChildren = DefaultDnsChildren;
	printf("Setting it to the default (%d).\n", DefaultDnsChildren);
    } else if (Config.dnsChildren > DefaultDnsChildrenMax) {
	printf("WARNING: dns_children was set to a bad value: %d\n",
	    Config.dnsChildren);
	printf("Setting it to the maximum (%d).\n", DefaultDnsChildrenMax);
	Config.dnsChildren = DefaultDnsChildrenMax;
    }
    if (Config.redirectChildren < 1) {
	printf("WARNING: redirect_children was set to a bad value: %d\n",
	    Config.redirectChildren);
	Config.redirectChildren = DefaultRedirectChildren;
	printf("Setting it to the default (%d).\n", DefaultRedirectChildren);
    } else if (Config.redirectChildren > DefaultRedirectChildrenMax) {
	printf("WARNING: redirect_children was set to a bad value: %d\n",
	    Config.redirectChildren);
	printf("Setting it to the maximum (%d).\n", DefaultRedirectChildrenMax);
	Config.redirectChildren = DefaultRedirectChildrenMax;
    }
    fclose(fp);

    configDoConfigure();
    return 0;
}
