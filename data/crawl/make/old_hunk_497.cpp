
		      if (i < 1 || cp[0] != '\0')
			{
                          error (NILF, _("the `-%c' option requires a positive integral argument"),
                                 cs->c);
			  bad = 1;
			}
