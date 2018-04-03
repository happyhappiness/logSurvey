
  if (count >= 0)
    fatal (reading_file,
	   _("unterminated call to function `%s': missing `%c'"),
	   entry_p->name, closeparen);

  /* Get some memory to store the arg pointers.  */
