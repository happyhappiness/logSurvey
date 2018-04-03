	    snprintf(fd_note_buf, FD_DESC_SZ, "%s #%d", s, dns_child_table[k]->id);
	    fd_note(dns_child_table[k]->inpipe, fd_note_buf);
	    commSetNonBlocking(dns_child_table[k]->inpipe);
	    debug(34, 3) ("dnsOpenServers: 'dns_server' %d started\n", k + 1);
	    NDnsServersAlloc++;
	}
    }
    if (NDnsServersAlloc == 0 && Config.dnsChildren > 0)
	fatal("Failed to start any dnsservers");
    cachemgrRegister("dns", "dnsserver child process information",
	dnsStats, 0, 1);
    debug(34, 1) ("Started %d 'dnsserver' processes\n", NDnsServersAlloc);
