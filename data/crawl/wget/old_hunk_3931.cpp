      else
	logprintf (LOG_VERBOSE, _("Removed `%s'.\n"), list_filename);
    }
  free (list_filename);
  con->cmd &= ~DO_LIST;
  return f;
}
