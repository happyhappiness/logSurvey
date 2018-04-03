    }

  *fd = -1;
  if (error_string == NULL)
    error_string = _("Cannot create a temporary file\n");
  fatal (NILF, error_string);

  /* not reached */
  return NULL;
