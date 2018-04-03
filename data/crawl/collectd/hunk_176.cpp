   {
     if (gps_open(gps_data_config.host, gps_data_config.port, &gps_data) < 0)
     {
-      printf ("cannot connect to: %s:%s", gps_data_config.host, gps_data_config.port);
+      WARNING ("gps: cannot connect to: %s:%s", gps_data_config.host, gps_data_config.port);
       sleep(60);
       continue;
     }
 
-    gps_stream(&gps_data, WATCH_ENABLE | WATCH_JSON, NULL);
+    gps_stream(&gps_data, WATCH_ENABLE | WATCH_JSON | WATCH_NEWSTYLE, NULL);
+    gps_send(&gps_data, "?WATCH={\"enable\":true,\"json\":true,\"nmea\":false}\r\n");
 
     while (1)
     {
-      if (gps_waiting (&gps_data, gps_data_config.timeout))
+      if (gps_waiting (&gps_data, gps_data_config.timeout ) )
       {
+        DEBUG ("gps: reading\n");
+
         if (gps_read (&gps_data) == -1)
         {
-            WARNING ("incorrect data.\n");
+            WARNING ("gps: incorrect data !\n");
         } 
         else {
           pthread_mutex_lock (&data_mutex);
+          DEBUG ("gps: parsing\n");
 
           // Dop data:
           if (isnan(gps_data.dop.vdop) == 0)
           {
+            DEBUG ("gps: isnan(gps_data.dop.vdop) == 0 [OK]\n");
             gps_data_read.vdop = gps_data.dop.vdop;
           }
           if (isnan(gps_data.dop.hdop) == 0)
           {
+            DEBUG ("gps: isnan(gps_data.dop.hdop) == 0 [OK]\n");
             gps_data_read.hdop = gps_data.dop.hdop;
           }
 
           // Sat in view:
           if ((gps_data.set & LATLON_SET))
           {
+            DEBUG ("gps: gps_data.set & LATLON_SET [OK] ... \n");
             gps_data_read.satellites = gps_data.satellites_used;
           }
+ 
+          DEBUG ("gps: raw is hdop=%1.3f, vdop=%1.3f, sat-used=%02d, lat=%02.05f, lon=%03.05f\n", 
+            gps_data.dop.hdop,
+            gps_data.dop.vdop,
+            gps_data.satellites_used,
+            gps_data.fix.latitude,
+            gps_data.fix.longitude
+          );
 
           pthread_mutex_unlock (&data_mutex);
+          sleep(gps_data_config.pause);
         }
       }
     }
