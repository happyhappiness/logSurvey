	  return err;
	case CONSSLERR:
	  /* Another fatal error.  */
	  logprintf (LOG_NOTQUIET, _("Unable to establish SSL connection.\n"));
	  free_hstat (&hstat);
	  xfree_null (dummy);
