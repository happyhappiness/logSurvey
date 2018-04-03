 {
   int err = 0;
 
-  printf ("gps: will use %s:%s with timeout %d.\n", gps_data_config.host, gps_data_config.port, gps_data_config.timeout);
+  DEBUG ("gps: will use %s:%s, timeout %d ms, pause %d sec.\n", gps_data_config.host, gps_data_config.port, gps_data_config.timeout, gps_data_config.pause);
 
   err = plugin_thread_create (&connector, NULL, gps_collectd_thread, NULL);
 
-  if (err != 0) {
-    WARNING ("pthread_create() failed.");
+  if (err != 0)
+  {
+    ERROR ("gps: pthread_create() failed.");
     return (-1);
   }
 
