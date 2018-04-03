
  fprintf (fh, "Severity: %s\n"
      "Time: %u\n"
      "Message: %s\n",
      severity, (unsigned int) n->time, n->message);

  /* Print the optional fields */
  if (strlen (n->host) > 0)
    fprintf (fh, "Host: %s\n", n->host);
  if (strlen (n->plugin) > 0)
    fprintf (fh, "Plugin: %s\n", n->plugin);
  if (strlen (n->plugin_instance) > 0)
    fprintf (fh, "PluginInstance: %s\n", n->plugin_instance);
  if (strlen (n->type) > 0)
    fprintf (fh, "Type: %s\n", n->type);
  if (strlen (n->type_instance) > 0)
    fprintf (fh, "TypeInstance: %s\n", n->type_instance);

  /* Newline signalling end of data */
  fprintf (fh, "\n");

  fflush (fh);
  fclose (fh);

