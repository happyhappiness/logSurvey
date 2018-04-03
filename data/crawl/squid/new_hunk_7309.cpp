	    k + 1,
	    DnsStats.hist[k]);
    }
    storeAppendPrintf(sentry, "{}\n");
    storeAppendPrintf(sentry, "{dnsservers status:}\n");
    for (k = 0; k < NDnsServersAlloc; k++) {
	dns = *(dns_child_table + k);
	storeAppendPrintf(sentry, "{dnsserver #%d:}\n", k + 1);
	storeAppendPrintf(sentry, "{    Flags: %c%c%c}\n",
	    dns->flags & DNS_FLAG_ALIVE ? 'A' : ' ',
	    dns->flags & DNS_FLAG_BUSY ? 'B' : ' ',
	    dns->flags & DNS_FLAG_CLOSING ? 'C' : ' ');
	storeAppendPrintf(sentry, "{    FDs (in/out): %d/%d}\n",
	    dns->inpipe, dns->outpipe);
	storeAppendPrintf(sentry, "{    Alive since: %s}\n",
	    mkrfc1123(dns->answer));
	storeAppendPrintf(sentry, "{    Last Dispatched: %0.3f seconds ago}\n",
	    0.001 * tvSubMsec(dns->dispatch_time, current_time));
	storeAppendPrintf(sentry, "{    Read Buffer Size: %d bytes}\n",
	    dns->size);
	storeAppendPrintf(sentry, "{    Read Offset: %d bytes}\n",
	    dns->offset);
    }
    storeAppendPrintf(sentry, "\n{Flags key:}\n\n");
    storeAppendPrintf(sentry, "{   A = ALIVE}\n");
    storeAppendPrintf(sentry, "{   B = BUSY}\n");
    storeAppendPrintf(sentry, "{   C = CLOSING}\n");

    storeAppendPrintf(sentry, close_bracket);
}

