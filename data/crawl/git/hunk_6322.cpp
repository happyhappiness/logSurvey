 				if (get_sha1_hex(rec + 41, sha1))
 					die("Log %s is corrupt.", logfile);
 				if (hashcmp(logged_sha1, sha1)) {
-					fprintf(stderr,
-						"warning: Log %s has gap after %s.\n",
+					warning("Log %s has gap after %s.",
 						logfile, show_date(date, tz, DATE_RFC2822));
 				}
 			}
