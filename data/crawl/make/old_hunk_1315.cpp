	  p += 5;
	  remove_comments (p);
	  if (*next_token (p) != '\0')
	    makefile_error (filename, lineno,
			    "Extraneous text after `endef' directive");
	  /* Define the variable.  */
	  if (idx == 0)
	    definition[0] = '\0';
