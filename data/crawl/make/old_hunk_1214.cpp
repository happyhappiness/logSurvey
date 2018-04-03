      if (word1eq ("override", 8))
        {
	  p2 = next_token (p + 8);
	  if (p2 == 0)
	    error (&fileinfo, "empty `override' directive");
	  if (!strncmp (p2, "define", 6) && (isblank (p2[6]) || p2[6] == '\0'))
	    {
