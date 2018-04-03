 */

int
main()
{
    char username[256];
    char password[256];
    char wstr[256];

    /* Read configuration file. Abort wildly if error. */
    if (OpenConfigFile() == 1)
	return 1;

    /* Read denied and allowed user files.
     * If they fails, there is a serious problem.
     * Check syslog messages. Deny all users while in this state.
     * The msntauth process should then be killed. */

    if ((Read_denyusers() == 1) || (Read_allowusers() == 1)) {
	while (1) {
	    fgets(wstr, 255, stdin);
	    puts("ERR");
	    fflush(stdout);
	}
    }
    /* Make Check_forchange() the handle for HUP signals.
     * Don't use alarms any more. I don't think it was very
     * portable between systems. */
    signal(SIGHUP, Check_forchange);

    while (1) {
	/* Read whole line from standard input. Terminate on break. */
	if (fgets(wstr, 255, stdin) == NULL)
	    break;

	/* Clear any current settings. Read new ones. Use \n as a 
	 * convenient EOL marker which is not even there. */
	username[0] = '\0';
	password[0] = '\0';
	sscanf(wstr, "%s %[^\n]", username, password);	/* Extract parameters */

	/* Check for invalid or blank entries */
	if ((username[0] == '\0') || (password[0] == '\0')) {
	    puts("ERR");
	    fflush(stdout);
	    continue;
	}
	Checktimer();		/* Check if the user lists have changed */

	/* Check if user is explicitly denied or allowed.
	 * If user passes both checks, they can be authenticated. */

	if (Check_user(username) == 1)
	    puts("ERR");
	else {
	    if (QueryServers(username, password) == 0)
		puts("OK");
	    else
		puts("ERR");
	}

	fflush(stdout);
    }

    return 0;
