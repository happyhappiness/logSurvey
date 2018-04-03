		fatal_dump("Invalid $ttl");
	    i.expires = squid_curtime + atoi(token);
	} else {
	    debug(14, 0, "--> %s <--\n", inbuf);
	    debug_trap("Invalid dnsserver output");
	}
    }
