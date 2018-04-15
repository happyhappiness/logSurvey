  sstrncpy (vl.host, hostname_g, sizeof (vl.host));
  sstrncpy (vl.plugin, "gps", sizeof (vl.plugin));
  sstrncpy (vl.type, type, sizeof (vl.type));
  sstrncpy (vl.type_instance, type_instance, sizeof (vl.type_instance));

  plugin_dispatch_values (&vl);
}


/**
 * Read the data and submit by piece.
 */
static int gps_collectd_read ()
{
  pthread_mutex_lock (&data_mutex);
  gps_collectd_submit("dilution_of_precision", (gauge_t) gps_data_read.hdop, "horizontal");
  gps_collectd_submit("dilution_of_precision", (gauge_t) gps_data_read.vdop, "vertical");
  gps_collectd_submit("satellites", (gauge_t) gps_data_read.satellites, "gps");
  DEBUG ("gps: hdop=%1.3f, vdop=%1.3f, sat=%02d.\n", 
    gps_data_read.hdop,
    gps_data_read.vdop,
    gps_data_read.satellites
