	    dns_child_table[k]->size = DNS_INBUF_SZ - 1;
	    dns_child_table[k]->offset = 0;
	    dns_child_table[k]->ip_inbuf = xcalloc(DNS_INBUF_SZ, 1);

	    /* update fd_stat */

	    sprintf(fd_note_buf, "%s #%d", prg, dns_child_table[k]->id);
	    fd_note(dns_child_table[k]->inpipe, fd_note_buf);
	    commSetNonBlocking(dns_child_table[k]->inpipe);
	    debug(34, 3, "dnsOpenServers: 'dns_server' %d started\n", k);
	    NDnsServersAlloc++;
	}
    }
}

