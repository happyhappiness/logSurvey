	mailname = fopen("/etc/mailname", "r");
	if (!mailname) {
		if (errno != ENOENT)
			warning_errno("cannot open /etc/mailname");
		return -1;
	}
	if (strbuf_getline(&mailnamebuf, mailname) == EOF) {
		if (ferror(mailname))
			warning_errno("cannot read /etc/mailname");
		strbuf_release(&mailnamebuf);
		fclose(mailname);
		return -1;
