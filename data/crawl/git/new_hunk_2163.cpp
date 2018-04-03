		else if (!strcmp(value, "always"))
			autorebase = AUTOREBASE_ALWAYS;
		else
			return error("malformed value for %s", var);
		return 0;
	}

