	      p = strchr (p2, '\0');
	      while (isblank ((unsigned char)p[-1]))
		--p;
	      do_define (p2, p - p2, o_file, ebuf);
	    }
	  continue;
	}

      if (word1eq ("override"))
        {
	  if (*p2 == '\0')
	    error (fstart, _("empty `override' directive"));

	  if (strneq (p2, "define", 6)
	      && (isblank ((unsigned char)p2[6]) || p2[6] == '\0'))
	    {
