		  if (optarg != 0)
		    {
		      int i = atoi (optarg);
		      if (i < 1)
			{
			  if (doit)
			    error (NILF, _("the `-%c' option requires a positive integral argument"),
				   cs->c);
			  bad = 1;
			}
		      else
