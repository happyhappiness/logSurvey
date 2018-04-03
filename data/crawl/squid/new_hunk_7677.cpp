	    printf("$end\n");
	    fflush(stdout);
	    continue;
#endif
	    addrbuf = inet_addr(request);
	    for (;;) {
		result = gethostbyaddr(&addrbuf, 4, AF_INET);
		if (result || h_errno != TRY_AGAIN)
		    break;
		if (++retry_count == 2)
		    break;
		sleep(2);
	    }
	} else {
	    for (;;) {
		result = gethostbyname(request);
		if (result || h_errno != TRY_AGAIN)
		    break;
		if (++retry_count == 2)
		    break;
		sleep(2);
	    }
	}
	stop = time(NULL);
