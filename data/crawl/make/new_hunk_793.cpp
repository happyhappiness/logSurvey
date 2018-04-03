
		  if (optarg == 0)
		    optarg = cs->noarg_value;
                  else if (*optarg == '\0')
                    {
                      error (NILF, _("the `-%c' option requires a non-empty string argument"),
                             cs->c);
                      bad = 1;
                    }

		  sl = *(struct stringlist **) cs->value_ptr;
		  if (sl == 0)
