	  matchres = fnmatch (u->file, f->name, 0);
	  if (matchres == -1)
	    {
	      logprintf (LOG_NOTQUIET, "%s: %s\n", con->target,
			 strerror (errno));
	      break;
	    }
