	    unsigned short rid;
	    int i;
	    int n;
	    struct in_addr addrs[10];
	    time_t ttl = 0;
	    char rname[RFC1035_MAXHOSTNAMESZ];
	    n = rfc1035ARecordsUnpack(rbuf,
		rl,
		addrs, 10,
		rname, RFC1035_MAXHOSTNAMESZ,
		&rid,
		&ttl);
	    if (rid != sid) {
		printf("ERROR, ID mismatch (%#hx, %#hx)\n", sid, rid);
	    } else if (n < 0) {
		printf("ERROR %d\n", rfc1035_errno);
	    } else {
		printf("name\t%s, %d A records\n", rname, n);
		printf("ttl\t%d\n", (int) ttl);
		for (i = 0; i < n; i++)
		    printf("addr %d\t%s\n", i, inet_ntoa(addrs[i]));
	    }
	}
    }