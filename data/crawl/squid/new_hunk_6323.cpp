	    snprintf(fd_note_buf, FD_DESC_SZ, "%s #%d", s, dns_child_table[k]->id);
	    fd_note(dns_child_table[k]->inpipe, fd_note_buf);
	    commSetNonBlocking(dns_child_table[k]->inpipe);
	    comm_add_close_handler(dns_child_table[k]->inpipe, dnsFDClosed,
		dns_child_table[k]);
	    debug(34, 3) ("dnsOpenServers: DNSSERVER #%d started\n", k + 1);
	    NDnsServersAlloc++;
	    NDnsServersRunning++;
	}
    }
    if (NDnsServersAlloc == 0 && Config.dnsChildren > 0)
	fatal("Failed to start any dnsservers");
    if (NDnsServersRunning < Config.dnsChildren / 2)
	fatal("Too few DNSSERVER processes are running");
    cachemgrRegister("dns", "dnsserver child process information",
	dnsStats, 0, 1);
    debug(34, 1) ("Started %d 'dnsserver' processes\n", NDnsServersAlloc);
