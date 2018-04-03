	    state = S_ERROR;
	  break;
	case S_NAME:
	  if (ATTR_NAME_CHAR (c))
	    FETCH1 (c, p);
	  else if (!c || c == ';' || c == '=' || ISSPACE (c))
	    {
	      name_e = p - 1;
	      state = S_NAME_POST;
	    }
	  else
	    state = S_ERROR;
	  break;
	case S_NAME_POST:
	  if (ISSPACE (c))
	    FETCH1 (c, p);
	  else if (!c || c == ';')
	    {
	      value_b = value_e = NULL;
	      state = S_ATTR_ACTION;
	    }
	  else if (c == '=')
	    {
	      FETCH1 (c, p);
	      state = S_VALUE_PRE;
	    }
	  else
	    state = S_ERROR;
	  break;
	case S_VALUE_PRE:
	  if (ISSPACE (c))
	    FETCH1 (c, p);
	  else if (c == '"')
	    {
	      value_b = p;
	      FETCH (c, p);
	      state = S_QUOTED_VALUE;
	    }
	  else if (c == ';' || c == '\0')
	    {
	      value_b = value_e = p - 1;
	      state = S_ATTR_ACTION;
	    }
	  else
	    {
	      value_b = p - 1;
	      value_e = NULL;
	      state = S_VALUE;
	    }
	  break;
	case S_VALUE:
	  if (c == ';' || c == '\0')
	    {
	      if (!value_e)
		value_e = p - 1;
	      state = S_ATTR_ACTION;
	    }
	  else if (ISSPACE (c))
	    {
	      value_e = p - 1;
	      FETCH1 (c, p);
	      state = S_VALUE_TRAILSPACE_MAYBE;
	    }
	  else
	    {
	      value_e = NULL;	/* no trailing space */
	      FETCH1 (c, p);
	    }
	  break;
	case S_VALUE_TRAILSPACE_MAYBE:
	  if (ISSPACE (c))
	    FETCH1 (c, p);
	  else
	    state = S_VALUE;
	  break;
	case S_QUOTED_VALUE:
	  if (c == '"')
	    {
	      value_e = p - 1;
	      FETCH1 (c, p);
	      state = S_QUOTED_VALUE_POST;
	    }
	  else
	    FETCH (c, p);
	  break;
	case S_QUOTED_VALUE_POST:
	  if (c == ';' || !c)
	    state = S_ATTR_ACTION;
	  else if (ISSPACE (c))
	    FETCH1 (c, p);
	  else
	    state = S_ERROR;
	  break;
	case S_ATTR_ACTION:
	  {
	    int legal = update_cookie_field (cookie, name_b, name_e,
					     value_b, value_e);
	    if (!legal)
	      {
		char *name;
		BOUNDED_TO_ALLOCA (name_b, name_e, name);
		logprintf (LOG_NOTQUIET,
			   _("Error in Set-Cookie, field `%s'"), name);
		state = S_ERROR;
		break;
	      }
	    state = S_NAME_PRE;
	  }
	  break;
	case S_DONE:
