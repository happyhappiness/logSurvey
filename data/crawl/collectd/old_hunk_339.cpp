  status = thread_init (&os_handler);
  if (status != 0)
  {
    fprintf (stderr, "ipmi plugin: thread_init failed.\n");
    return ((void *) -1);
  }

