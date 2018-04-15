  {
    if (gps_open(gps_data_config.host, gps_data_config.port, &gps_data) < 0)
    {
      printf ("cannot connect to: %s:%s", gps_data_config.host, gps_data_config.port);
      sleep(60);
      continue;
    }

    gps_stream(&gps_data, WATCH_ENABLE | WATCH_JSON, NULL);

    while (1)
    {
      if (gps_waiting (&gps_data, gps_data_config.timeout))
      {
        if (gps_read (&gps_data) == -1)
        {
            WARNING ("incorrect data.\n");
        } 
        else {
          pthread_mutex_lock (&data_mutex);

          // Dop data:
          if (isnan(gps_data.dop.vdop) == 0)
          {
            gps_data_read.vdop = gps_data.dop.vdop;
          }
          if (isnan(gps_data.dop.hdop) == 0)
          {
            gps_data_read.hdop = gps_data.dop.hdop;
          }

          // Sat in view:
          if ((gps_data.set & LATLON_SET))
          {
            gps_data_read.satellites = gps_data.satellites_used;
          }

          pthread_mutex_unlock (&data_mutex);
        }
      }
    }
