     }
     if (NDnsServersAlloc == 0 && Config.dnsChildren > 0)
 	fatal("Failed to start any dnsservers");
+    cachemgrRegister("dns", "dnsserver child process information",
+	dnsStats, 0);
     debug(34, 1) ("Started %d 'dnsserver' processes\n", NDnsServersAlloc);
 }
 
