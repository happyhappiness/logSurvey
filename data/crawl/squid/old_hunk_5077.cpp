	    alarm(0);
	    signal(SIGALRM, SIG_DFL);
	    if (got_timeout != 0) {
		fprintf(stderr, "ntlm-auth[%d]: Timeout during authentication.\n", getpid());
		SEND("BH Timeout during authentication");
		got_timeout = 0;
		return;
