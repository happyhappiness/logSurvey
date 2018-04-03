       /* Avoid spurious rebuilds due to low resolution time stamps.  */
       int ns = FILE_TIMESTAMP_NS (this_mtime);
       if (ns != 0)
-        error (NILF, _("*** Warning: .LOW_RESOLUTION_TIME file '%s' has a high resolution time stamp"),
-               file->name);
+        OS (error, NILF,
+            _("*** Warning: .LOW_RESOLUTION_TIME file '%s' has a high resolution time stamp"),
+            file->name);
       this_mtime += FILE_TIMESTAMPS_PER_S - 1 - ns;
     }
 
