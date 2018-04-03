	forward = parse_binary_hunk(&buffer, &size, &status, &used);
	if (!forward && !status)
		/* there has to be one hunk (forward hunk) */
		return error(_("unrecognized binary patch at line %d"), state_linenr-1);
	if (status)
		/* otherwise we already gave an error message */
		return status;
