	    alarm(0);
	    signal(SIGALRM, SIG_DFL);
	    if (got_timeout != 0) {
		fprintf(stderr, "ntlm-auth[%ld]: Timeout during authentication.\n", (long)getpid());
		SEND("BH Timeout during authentication");
		got_timeout = 0;
		return;
