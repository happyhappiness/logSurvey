	sigChldAction.sa_handler = SIG_IGN;
	sigaction (SIGCHLD, &sigChldAction, NULL);

	if (daemonize)
	{
		if ((pid = fork ()) == -1)
