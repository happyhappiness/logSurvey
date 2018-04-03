    if (proxy_user) {
	char *user = proxy_user;
	char *password = proxy_password;
	if (!password)
	    password = getpass("Proxy password: ");
	if (password) {
	    snprintf(buf, BUFSIZ, "%s:%s", user, password);
	    snprintf(buf, BUFSIZ, "Proxy-Authorization: Basic %s\n", base64_encode(buf));
	    strcat(msg, buf);
	}
    }
    if (www_user) {
	char *user = www_user;
	char *password = www_password;
	if (!password)
	    password = getpass("WWW password: ");
	if (password) {
	    snprintf(buf, BUFSIZ, "%s:%s", user, password);
	    snprintf(buf, BUFSIZ, "Authorization: Basic %s\n", base64_encode(buf));
	    strcat(msg, buf);
	}
    }
    if (keep_alive) {
	if (port != 80)