	email = getenv("GIT_AUTHOR_EMAIL");
	date = getenv("GIT_AUTHOR_DATE");

	if (use_message && !renew_authorship) {
		const char *a, *lb, *rb, *eol;

		a = strstr(use_message_buffer, "\nauthor ");
		if (!a)
			die("invalid commit: %s", use_message);

		lb = strchrnul(a + strlen("\nauthor "), '<');
		rb = strchrnul(lb, '>');
		eol = strchrnul(rb, '\n');
		if (!*lb || !*rb || !*eol)
			die("invalid commit: %s", use_message);

		if (lb == a + strlen("\nauthor "))
			/* \nauthor <foo@example.com> */
