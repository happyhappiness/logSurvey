		ref = NULL;
	ret = !ref;

	if (!ret && sought.nr) {
		/* If the heads to pull were given, we should have
		 * consumed all of them by matching the remote.
		 * Otherwise, 'git fetch remote no-such-ref' would
		 * silently succeed without issuing an error.
		 */
		for (i = 0; i < sought.nr; i++) {
			char *s = sought.items[i].string;
			if (s && s[0]) {
				error("no such remote ref %s", s);
				ret = 1;
			}
		}
	}
	while (ref) {
		printf("%s %s\n",
