				continue;
			}
			if (!strncmp(arg, "--date=", 7)) {
				if (!strcmp(arg + 7, "relative"))
					revs->date_mode = DATE_RELATIVE;
				else if (!strcmp(arg + 7, "iso8601") ||
					 !strcmp(arg + 7, "iso"))
					revs->date_mode = DATE_ISO8601;
				else if (!strcmp(arg + 7, "rfc2822") ||
					 !strcmp(arg + 7, "rfc"))
					revs->date_mode = DATE_RFC2822;
				else if (!strcmp(arg + 7, "short"))
					revs->date_mode = DATE_SHORT;
				else if (!strcmp(arg + 7, "local"))
					revs->date_mode = DATE_LOCAL;
				else if (!strcmp(arg + 7, "default"))
					revs->date_mode = DATE_NORMAL;
				else
					die("unknown date format %s", arg);
				continue;
			}
			if (!strcmp(arg, "--log-size")) {