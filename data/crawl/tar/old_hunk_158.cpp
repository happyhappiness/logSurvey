
	if (arg[1])
	  argp_error (state, _("Malformed density argument: %s"), quote (arg));
	
	strcpy (buf, DEVICE_PREFIX);
	cursor = buf + strlen (buf);

#ifdef DENSITY_LETTER

	sprintf (cursor, "%d%c", device, arg[0]);
	
#else /* not DENSITY_LETTER */

	switch (arg[0])
