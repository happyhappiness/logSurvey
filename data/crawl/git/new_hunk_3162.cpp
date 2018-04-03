		  return 0;
	}

	if (flag & REF_ISBROKEN) {
		  warning("ignoring broken ref %s", refname);
		  return 0;
	}

	if (*cb->grab_pattern) {
		const char **pattern;
		int namelen = strlen(refname);
