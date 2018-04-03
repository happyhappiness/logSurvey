                 (FILE_TIMESTAMP_S (mtime) - FILE_TIMESTAMP_S (now)
                  + ((FILE_TIMESTAMP_NS (mtime) - FILE_TIMESTAMP_NS (now))
                     / 1e9));
-              error (NILF, _("Warning: File `%s' has modification time %.2g s in the future"),
-                     file->name, from_now);
+              char from_now_string[100];
+
+              if (from_now >= 99 && from_now <= ULONG_MAX)
+                sprintf (from_now_string, "%lu", (unsigned long) from_now);
+              else
+                sprintf (from_now_string, "%.2g", from_now);
+              error (NILF, _("Warning: File `%s' has modification time %s s in the future"),
+                     file->name, from_now_string);
 #endif
               clock_skew_detected = 1;
             }
