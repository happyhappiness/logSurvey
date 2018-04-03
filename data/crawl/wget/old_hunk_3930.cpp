	  char *hurl = str_url (u->proxy ? u->proxy : u, 1);
	  logprintf (LOG_NONVERBOSE, "%s URL: %s [%ld] -> \"%s\" [%d]\n",
		     tms, hurl, len, locf, count);
	  free (hurl);
	}

      if ((con->cmd & DO_LIST))
