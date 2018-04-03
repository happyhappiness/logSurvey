 
     if (ping && i) {
         ping_mean = ping_sum / i;
-        fprintf(stderr, "%d requests, round-trip (secs) min/avg/max = "
-                "%ld.%03ld/%ld.%03ld/%ld.%03ld\n", i,
-                ping_min / 1000, ping_min % 1000, ping_mean / 1000, ping_mean % 1000,
-                ping_max / 1000, ping_max % 1000);
+        std::cerr << i << " requests, round-trip (secs) min/avg/max = "
+                  << (ping_min/1000) << "." << (ping_min%1000)
+                  << "/" << (ping_mean/1000) << "." << (ping_mean%1000)
+                  << "/" << (ping_max/1000) << "." << (ping_max%1000)
+                  << std::endl;
     }
-    exit(0);
-    /*NOTREACHED */
     return 0;
 }
 