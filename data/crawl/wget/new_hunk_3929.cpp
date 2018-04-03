	  while ((line = read_whole_line (fp)))
	    {
	      logprintf (LOG_ALWAYS, "%s\n", line);
	      xfree (line);
	    }
	  fclose (fp);
	}
