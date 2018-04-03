	if (Config.Accel.port == 0)
	    vport_mode = 1;
    }
    snprintf(ThisCache, sizeof(ThisCache), "%s (%s)",
	uniqueHostname(),
	full_appname_string);
    /*
     * the extra space is for loop detection in client_side.c -- we search
     * for substrings in the Via header.
     */
    snprintf(ThisCache2, sizeof(ThisCache), " %s (%s)",
	uniqueHostname(),
	full_appname_string);
    if (!Config.udpMaxHitObjsz || Config.udpMaxHitObjsz > SQUID_UDP_SO_SNDBUF)
	Config.udpMaxHitObjsz = SQUID_UDP_SO_SNDBUF;
