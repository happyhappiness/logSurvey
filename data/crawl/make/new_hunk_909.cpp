		  if (optarg != 0)
		    {
		      int i = atoi (optarg);
                      const char *cp;

                      /* Yes, I realize we're repeating this in some cases.  */
                      for (cp = optarg; ISDIGIT (cp[0]); ++cp)
                        ;

		      if (i < 1 || cp[0] != '\0')
			{
                          error (NILF, _("the `-%c' option requires a positive integral argument"),
                                 cs->c);
			  bad = 1;
			}
		      else
