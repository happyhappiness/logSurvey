	}
	safe_free(tmp_line);
    }
    fclose(fp);
    defaults_if_none();
    configDoConfigure();
    return 0;
}

static void
configDoConfigure(void)
{
    LOCAL_ARRAY(char, buf, BUFSIZ);
    memset(&Config2, '\0', sizeof(SquidConfig2));
    /* Sanity checks */
    if (Config.cacheSwap.swapDirs == NULL)
	fatal("No cache_dir's specified in config file");
    if (Config.Swap.maxSize < (Config.Mem.maxSize >> 10))
	fatal("cache_swap is lower than cache_mem");
    if (Config.Announce.period < 1) {
	Config.Announce.period = 86400 * 365;	/* one year */
	Config.onoff.announce = 0;
    }
    if (Config.dnsChildren < 1)
	fatal("No dnsservers allocated");
    if (Config.dnsChildren > DefaultDnsChildrenMax) {
	debug(3, 0) ("WARNING: dns_children was set to a bad value: %d\n",
	    Config.dnsChildren);
	debug(3, 0) ("Setting it to the maximum (%d).\n",
	    DefaultDnsChildrenMax);
	Config.dnsChildren = DefaultDnsChildrenMax;
    }
    if (Config.Program.redirect) {
	if (Config.redirectChildren < 1) {
	    Config.redirectChildren = 0;
	    safe_free(Config.Program.redirect);
	} else if (Config.redirectChildren > DefaultRedirectChildrenMax) {
	    debug(3, 0) ("WARNING: redirect_children was set to a bad value: %d\n",
		Config.redirectChildren);
	    debug(3, 0) ("Setting it to the maximum (%d).\n", DefaultRedirectChildrenMax);
	    Config.redirectChildren = DefaultRedirectChildrenMax;
	}
    }
    if (Config.Accel.host) {
	snprintf(buf, BUFSIZ, "http://%s:%d", Config.Accel.host, Config.Accel.port);
	Config2.Accel.prefix = xstrdup(buf);
