	      || word1eq ("ifeq", 4) || word1eq ("ifneq", 5)
	      || word1eq ("else", 4) || word1eq ("endif", 5)))
	{
	  int i = conditional_line (p, filename, lineno);
	  if (i >= 0)
	    ignoring = i;
	  else
	    makefile_fatal (filename, lineno,
			    "invalid syntax in conditional");
	  continue;
	}

