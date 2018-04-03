		    break;

		  if (optarg == 0)
		    optarg = xstrdup (cs->noarg_value);
                  else if (*optarg == '\0')
                    {
                      error (NILF, _("the `-%c' option requires a non-empty string argument"),
