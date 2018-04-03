    if (proxy_user) {
	char *user = proxy_user;
	char *password = proxy_password;
#if HAVE_GETPASS
	if (!password)
	    password = getpass("Proxy password: ");
#endif
	if (!password) {
	    fprintf(stderr, "ERROR: Proxy password missing\n");
	    exit(1);
	}
	snprintf(buf, BUFSIZ, "%s:%s", user, password);
	snprintf(buf, BUFSIZ, "Proxy-Authorization: Basic %s\n", base64_encode(buf));
	strcat(msg, buf);
    }
    if (www_user) {
	char *user = www_user;
	char *password = www_password;
#if HAVE_GETPASS
	if (!password)
	    password = getpass("WWW password: ");
#endif
	if (!password) {
	    fprintf(stderr, "ERROR: WWW password missing\n");
	    exit(1);
	}
	snprintf(buf, BUFSIZ, "%s:%s", user, password);
	snprintf(buf, BUFSIZ, "Authorization: Basic %s\n", base64_encode(buf));
	strcat(msg, buf);
    }
    if (keep_alive) {
	if (port != 80)