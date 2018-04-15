  if (strlen (n->type_instance) > 0)
    fprintf (fh, "TypeInstance: %s\n", n->type_instance);

  /* Newline signalling end of data */
  fprintf (fh, "\n");

  fflush (fh);
  fclose (fh);