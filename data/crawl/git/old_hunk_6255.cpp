				if (get_sha1_hex(rec + 41, logged_sha1))
					die("Log %s is corrupt.", logfile);
				if (hashcmp(logged_sha1, sha1)) {
					fprintf(stderr,
						"warning: Log %s unexpectedly ended on %s.\n",
						logfile, show_date(date, tz, DATE_RFC2822));
				}
			}
