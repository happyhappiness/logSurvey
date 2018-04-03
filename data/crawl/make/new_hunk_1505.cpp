	       line with the description, leaving at least two spaces.
	       Print it on its own line instead.  */
	    {
	      fprintf (usageto, "%s\n", buf);
	      buf[0] = '\0';
	    }

	  fprintf (usageto, "%*s%s.\n",
		   - DESCRIPTION_COLUMN,
		   buf, cs->description);
	}
