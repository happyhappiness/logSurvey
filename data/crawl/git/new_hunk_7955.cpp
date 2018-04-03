				continue;
			}
			if (!strncmp(arg, "--date=", 7)) {
				revs->date_mode = parse_date_format(arg + 7);
				continue;
			}
			if (!strcmp(arg, "--log-size")) {