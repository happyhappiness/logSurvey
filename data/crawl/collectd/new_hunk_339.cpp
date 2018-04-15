  status = thread_init (&os_handler);
  if (status != 0)
  {
    ERROR ("ipmi plugin: thread_init failed.\n");
    return ((void *) -1);
  }

