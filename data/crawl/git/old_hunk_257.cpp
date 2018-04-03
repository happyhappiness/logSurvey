
			errno = 0;
			timestamp = parse_timestamp(str, &end, 10);
			if (errno)
				return error(_("invalid timestamp"));

			if (!skip_prefix(end, " ", &str))
				return error(_("invalid Date line"));

			errno = 0;
			tz = strtol(str, &end, 10);
			if (errno)
				return error(_("invalid timezone offset"));

			if (*end)
				return error(_("invalid Date line"));

			/*
			 * mercurial's timezone is in seconds west of UTC,
