		else if (!strcmp(value, "current"))
			push_default = PUSH_DEFAULT_CURRENT;
		else {
			error("Malformed value for %s: %s", var, value);
			return error("Must be one of nothing, matching, simple, "
				     "upstream or current.");
		}
