
	rej = fopen(namebuf, "w");
	if (!rej)
		return error(_("cannot open %s: %s"), namebuf, strerror(errno));

	/* Normal git tools never deal with .rej, so do not pretend
	 * this is a git patch by saying --git or giving extended