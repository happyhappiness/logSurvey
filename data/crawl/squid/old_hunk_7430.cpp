		fatal_dump("Invalid $ttl");
	    i.expires = squid_curtime + atoi(token);
	} else {
	    fatal_dump("Invalid dnsserver output");
	}
    }
    xfree(buf);