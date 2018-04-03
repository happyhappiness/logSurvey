     call malloc.  */
  log_set_save_context (false);
  logprintf (LOG_ALWAYS,
	     _("%s: %s: Failed to allocate %ld bytes; memory exhausted.\n"),
	     exec_name, context, attempted_size);
  exit (1);
}

