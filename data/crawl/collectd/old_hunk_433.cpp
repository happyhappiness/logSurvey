  if (strlen (n->type_instance) > 0)
    fprintf (fh, "TypeInstance: %s\n", n->type_instance);

  fprintf (fh, "\n%s\n", n->message);

  fflush (fh);
