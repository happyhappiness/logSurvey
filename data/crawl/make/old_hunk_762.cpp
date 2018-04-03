    }
  strcpy (p, *argvp);

  if (*funcname == 'e')
    fatal (reading_file, "%s", msg);

  /* The warning function expands to the empty string.  */
  error (reading_file, "%s", msg);

  return o;
}

