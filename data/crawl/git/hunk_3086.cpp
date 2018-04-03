 			hashcpy(cb->sha1, nsha1);
 			if (hashcmp(cb->osha1, nsha1))
 				warning("Log for ref %s has gap after %s.",
-					cb->refname, show_date(cb->date, cb->tz, DATE_RFC2822));
+					cb->refname, show_date(cb->date, cb->tz, DATE_MODE(RFC2822)));
 		}
 		else if (cb->date == cb->at_time)
 			hashcpy(cb->sha1, nsha1);
 		else if (hashcmp(nsha1, cb->sha1))
 			warning("Log for ref %s unexpectedly ended on %s.",
 				cb->refname, show_date(cb->date, cb->tz,
-						   DATE_RFC2822));
+						       DATE_MODE(RFC2822)));
 		hashcpy(cb->osha1, osha1);
 		hashcpy(cb->nsha1, nsha1);
 		cb->found_it = 1;