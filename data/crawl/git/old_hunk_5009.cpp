		askpass = askpass_program;
	if (!askpass)
		askpass = getenv("SSH_ASKPASS");
	if (!askpass || !(*askpass))
		return getpass(prompt);

	args[0] = askpass;
	args[1]	= prompt;