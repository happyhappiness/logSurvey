     /*
      * Calculate a new reserve, based on current usage and a small extra
      */
-    new = Squid_MaxFD - Number_FD + XMIN(25, Squid_MaxFD / 16);
-    if (new <= RESERVED_FD)
+    newReserve = Squid_MaxFD - Number_FD + XMIN(25, Squid_MaxFD / 16);
+    if (newReserve <= RESERVED_FD)
 	return;
     x = Squid_MaxFD - 20 - XMIN(25, Squid_MaxFD / 16);
-    if (new > x) {
+    if (newReserve > x) {
 	/* perhaps this should be fatal()? -DW */
 	debug(51, 0) ("WARNING: This machine has a serious shortage of filedescriptors.\n");
-	new = x;
+	newReserve = x;
     }
     debug(51, 0) ("Reserved FD adjusted from %d to %d due to failures\n",
-	RESERVED_FD, new);
-    RESERVED_FD = new;
+	RESERVED_FD, newReserve);
+    RESERVED_FD = newReserve;
 }
