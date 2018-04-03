    if (getDnsChildren() < 1) {
	printf("WARNING: dns_children was set to a bad value: %d\n",
	    getDnsChildren());
	printf("Setting it to the default (3).\n");
	Config.dnsChildren = 3;
    } else if (getDnsChildren() > DefaultDnsChildrenMax) {
	printf("WARNING: dns_children was set to a bad value: %d\n",
	    getDnsChildren());
	printf("Setting it to the maximum (%d).\n", DefaultDnsChildrenMax);
	Config.dnsChildren = DefaultDnsChildrenMax;
    }
    fclose(fp);

    configDoConfigure();
