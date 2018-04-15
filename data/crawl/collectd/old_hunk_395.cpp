
  fprintf (fh, "Severity: %s\n"
      "Time: %u\n"
      "Host: %s\n"
      "Message: %s\n"
      "\n",
      severity, (unsigned int) n->time, n->host, n->message);
  fflush (fh);
  fclose (fh);

