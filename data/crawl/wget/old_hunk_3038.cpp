		    char *name;
		    BOUNDED_TO_ALLOCA (name_b, name_e, name);
		    logprintf (LOG_NOTQUIET,
			       _("Error in Set-Cookie, field `%s'"), name);
		  }
		state = S_ERROR;
		break;
