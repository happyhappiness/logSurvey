	  while ((line = read_whole_line (fp)))
	    {
	      logprintf (LOG_ALWAYS, "%s\n", line);
	      free (line);
	    }
	  fclose (fp);
	}
