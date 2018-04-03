 	    NDnsServersAlloc++;
 	}
     }
-    if (NDnsServersAlloc == 0)
+    if (NDnsServersAlloc == 0 && Config.dnsChildren > 0)
 	fatal("Failed to start any dnsservers");
     debug(34, 1, "Started %d 'dnsserver' processes\n", NDnsServersAlloc);
 }
