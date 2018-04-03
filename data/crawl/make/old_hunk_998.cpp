  if (argv[0] != NULL && argv[1] != NULL)
    {
      char *expansion;
      char **endp = argv+1;

      /* If we're doing the else-clause, make sure we concatenate any
         potential extra arguments into the last argument.  */
      if (!result)
        while (*endp && **endp != '\0')
          ++endp;

      expansion = expand_argument (*argv, *endp-1);

      o = variable_buffer_output (o, expansion, strlen (expansion));
      free (expansion);
