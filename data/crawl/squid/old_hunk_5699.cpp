    NULL
};

void
signal_received(int sig)
{
    reset_pam = 1;
    signal(sig, signal_received);
}

int
main(int argc, char *argv[])
{
    pam_handle_t *pamh = NULL;
    int retval;
    char *user;
    /* char *password; */
    char buf[BUFSIZE];
    time_t pamh_created = 0;

    signal(SIGHUP, signal_received);

    /* make standard output line buffered */
    setvbuf(stdout, NULL, _IOLBF, 0);

    while (retval = PAM_SUCCESS, fgets(buf, BUFSIZE, stdin)) {
	user = buf;
	password = strchr(buf, '\n');
	if (!password) {
	    fprintf(stderr, "authenticator: Unexpected input '%s'\n", buf);
	    fprintf(stdout, "ERR\n");
	    continue;
	}
	*password = '\0';
	password = strchr(buf, ' ');
	if (!password) {
	    fprintf(stderr, "authenticator: Unexpected input '%s'\n", buf);
	    fprintf(stdout, "ERR\n");
	    continue;
	}
	*password++ = '\0';
	conv.appdata_ptr = (char *) password;	/* from buf above. not allocated */
#ifdef PAM_CONNECTION_TTL
	if (pamh_created + PAM_CONNECTION_TTL >= time(NULL))
	    reset_pam = 1;
#endif
	if (reset_pam && pamh) {
	    /* Close previous PAM connection */
	    retval = pam_end(pamh, retval);
	    if (retval != PAM_SUCCESS) {
		fprintf(stderr, "ERROR: failed to release PAM authenticator\n");
	    }
	    pamh = NULL;
	}
	if (!pamh) {
	    /* Initialize PAM connection */
	    retval = pam_start(SQUID_PAM_SERVICE, "squid@", &conv, &pamh);
	    if (retval != PAM_SUCCESS) {
		fprintf(stderr, "ERROR: failed to create PAM authenticator\n");
	    }
	    reset_pam = 0;
	    pamh_created = time(NULL);
	}
	if (retval == PAM_SUCCESS)
	    retval = pam_set_item(pamh, PAM_USER, user);
	if (retval == PAM_SUCCESS)
	    retval = pam_set_item(pamh, PAM_CONV, &conv);
	if (retval == PAM_SUCCESS)
	    retval = pam_authenticate(pamh, 0);
	if (retval == PAM_SUCCESS)
	    retval = pam_acct_mgmt(pamh, 0);
	if (retval == PAM_SUCCESS) {
	    fprintf(stdout, "OK\n");
	} else {
	    fprintf(stdout, "ERR\n");
	}
    }

    if (pamh) {
