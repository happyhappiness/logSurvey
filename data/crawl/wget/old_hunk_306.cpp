  for (i = 1; i < argc; i++)
    argstring_length += strlen (argv[i]) + 2 + 1;
  char *p = program_argstring = malloc (argstring_length * sizeof (char));
  for (i = 1; i < argc; i++)
  {
    *p++ = '"';
    int arglen = strlen (argv[i]);
    memcpy (p, argv[i], arglen);
    p += arglen;
    *p++ = '"';
    *p++ = ' ';
  }
  *p = '\0';

  /* Load the hard-coded defaults.  */
