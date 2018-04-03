	    printf("$end\n");
	    fflush(stdout);
	    continue;
	}
	start = time(NULL);
	result = gethostbyname(request);
	if (!result) {
	    if (h_errno == TRY_AGAIN) {
		sleep(2);
		result = gethostbyname(request);	/* try a little harder */
	    }
	}
	stop = time(NULL);
