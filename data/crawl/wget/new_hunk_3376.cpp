	    state = S_ERROR;
	  break;
	case S_NAME:
	  if (!c || c == ';' || c == '=' || ISSPACE (c))
	    {
	      name_e = p;
	      state = S_NAME_POST;
	    }
	  else if (ATTR_NAME_CHAR (c))
	    c = *++p;
	  else
	    state = S_ERROR;
	  break;
	case S_NAME_POST:
	  if (!c || c == ';')
	    {
	      value_b = value_e = NULL;
	      if (c == ';')
		c = *++p;
	      state = S_ATTR_ACTION;
	    }
	  else if (c == '=')
	    {
	      c = *++p;
	      state = S_VALUE_PRE;
	    }
	  else if (ISSPACE (c))
	    /* Ignore space and keep the state. */
	    c = *++p;
	  else
	    state = S_ERROR;
	  break;
	case S_VALUE_PRE:
	  if (!c || c == ';')
	    {
	      value_b = value_e = p;
	      if (c == ';')
		c = *++p;
	      state = S_ATTR_ACTION;
	    }
	  else if (c == '"')
	    {
	      c = *++p;
	      value_b = p;
	      state = S_QUOTED_VALUE;
	    }
	  else if (ISSPACE (c))
	    c = *++p;
	  else
	    {
	      value_b = p;
	      value_e = NULL;
	      state = S_VALUE;
	    }
	  break;
	case S_VALUE:
	  if (!c || c == ';' || ISSPACE (c))
	    {
	      value_e = p;
	      state = S_VALUE_TRAILSPACE;
	    }
	  else
	    {
	      value_e = NULL;	/* no trailing space */
	      c = *++p;
	    }
	  break;
	case S_QUOTED_VALUE:
	  if (c == '"')
	    {
	      value_e = p;
	      c = *++p;
	      state = S_VALUE_TRAILSPACE;
	    }
	  else if (!c)
	    state = S_ERROR;
	  else
	    c = *++p;
	  break;
	case S_VALUE_TRAILSPACE:
	  if (c == ';')
	    {
	      c = *++p;
	      state = S_ATTR_ACTION;
	    }
	  else if (!c)
	    state = S_ATTR_ACTION;
	  else if (ISSPACE (c))
	    c = *++p;
	  else
	    state = S_VALUE;
	  break;
	case S_ATTR_ACTION:
	  {
	    int legal = callback (cookie, name_b, name_e, value_b, value_e);
	    if (!legal)
	      {
		if (!silent)
		  {
		    char *name;
		    BOUNDED_TO_ALLOCA (name_b, name_e, name);
		    logprintf (LOG_NOTQUIET,
			       _("Error in Set-Cookie, field `%s'"), name);
		  }
		state = S_ERROR;
		break;
	      }
	    state = S_START;
	  }
	  break;
	case S_DONE:
