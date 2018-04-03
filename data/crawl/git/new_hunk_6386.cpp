	args[i++] = NULL;

	if (run_command(&rsync))
		return error("Could not push objects to %s",
				rsync_url(transport->url));

	/* copy the refs to the temporary directory; they could be packed. */

