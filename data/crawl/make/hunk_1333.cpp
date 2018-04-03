 #endif
 #endif
           {
-            error("*** Warning: File `%s' has modification time in the future (%ld > %ld)",
-                  file->name, mtime, now);
+	    char mtimebuf[FILE_TIMESTAMP_PRINT_LEN_BOUND + 1];
+	    char nowbuf[FILE_TIMESTAMP_PRINT_LEN_BOUND + 1];
+
+	    file_timestamp_sprintf (mtimebuf, mtime);
+	    file_timestamp_sprintf (nowbuf, now);
+            error (NILF, "*** Warning: File `%s' has modification time in the future (%s > %s)",
+                   file->name, mtimebuf, nowbuf);
             clock_skew_detected = 1;
           }
       }