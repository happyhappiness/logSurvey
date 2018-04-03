      else
	logprintf (LOG_VERBOSE, _("Removed `%s'.\n"), list_filename);
    }
  xfree (list_filename);
  con->cmd &= ~DO_LIST;
  return f;
}
