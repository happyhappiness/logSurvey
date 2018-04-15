{
  int err = 0;

  printf ("gps: will use %s:%s with timeout %d.\n", gps_data_config.host, gps_data_config.port, gps_data_config.timeout);

  err = plugin_thread_create (&connector, NULL, gps_collectd_thread, NULL);

  if (err != 0) {
    WARNING ("pthread_create() failed.");
    return (-1);
  }

