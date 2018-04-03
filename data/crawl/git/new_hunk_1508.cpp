
	rej = fopen(namebuf, "w");
	if (!rej)
		return error_errno(_("cannot open %s"), namebuf);

	/* Normal git tools never deal with .rej, so do not pretend
	 * this is a git patch by saying --git or giving extended