
			errno = 0;
			timestamp = parse_timestamp(str, &end, 10);
			if (errno) {
				rc = error(_("invalid timestamp"));
				goto exit;
			}

			if (!skip_prefix(end, " ", &str)) {
				rc = error(_("invalid Date line"));
				goto exit;
			}

			errno = 0;
			tz = strtol(str, &end, 10);
			if (errno) {
				rc = error(_("invalid timezone offset"));
				goto exit;
			}

			if (*end) {
				rc = error(_("invalid Date line"));
				goto exit;
			}

			/*
			 * mercurial's timezone is in seconds west of UTC,
