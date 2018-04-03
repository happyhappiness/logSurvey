		fflush(logfile);
	    }
	    printf("$fail %s\n", request);
	    printf("$message %s\n", msg[0] ? msg : "Unknown Error");
	    printf("$end\n");
	    fflush(stdout);
	    continue;
