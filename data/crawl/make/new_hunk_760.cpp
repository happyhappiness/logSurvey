	    }
	  else
	    {
	      /* We use subst_expand to do the work of translating
		 % to $* in the dependency line.  */

              if (this != 0 && find_percent (this->name) != 0)
                {
                  char *o;
                  char *buffer = variable_expand ("");

                  o = subst_expand (buffer, this->name, "%", "$*",
                                    1, 2, 0);

		  free (this->name);
		  this->name = savestring (buffer, o - buffer);
		}
