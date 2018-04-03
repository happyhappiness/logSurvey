			char *end;
			opts->depth = strtol(value, &end, 0);
			if (*end)
				die("transport: invalid depth option '%s'", value);
		}
		return 0;
	}
