	rfc1738_unescape(passwd);
	pwd = getpwnam(user);
	if (pwd == NULL) {
	    printf(ERR);
	} else {
	    if (strcmp(pwd->pw_passwd, (char *) crypt(passwd, pwd->pw_passwd))) {
		printf(ERR);
	    } else {
		printf(OK);
	    }
