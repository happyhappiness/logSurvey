	  /* Need to hide the password from the URL.  The `if' is here
             so that we don't do the needless allocation every
             time. */
	  char *hurl = str_url (u->proxy ? u->proxy : u, 1);
	  logprintf (LOG_NONVERBOSE, "%s URL: %s [%ld] -> \"%s\" [%d]\n",
		     tms, hurl, len, locf, count);
	  xfree (hurl);
