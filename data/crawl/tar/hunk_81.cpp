       return;
     }
 
+  if (status % BLOCKSIZE)
+    {
+      ERROR ((0, 0, _("write did not end on a block boundary")));
+      archive_write_error (status);
+    }
+  
   /* In multi-volume mode. */
   /* ENXIO is for the UNIX PC.  */
   if (status < 0 && errno != ENOSPC && errno != EIO && errno != ENXIO)
     archive_write_error (status);
 
+  real_s_sizeleft -= status;
   if (!new_volume (ACCESS_WRITE))
     return;
 
