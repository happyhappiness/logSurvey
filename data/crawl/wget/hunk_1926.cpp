      zeroes from the mmaped region.  */
   if (unlink (file) < 0 && errno != ENOENT)
     {
-      logprintf (LOG_NOTQUIET, _("Unable to delete `%s': %s\n"),
-                 file, strerror (errno));
+      logprintf (LOG_NOTQUIET, _("Unable to delete %s: %s\n"),
+                 quote (file), strerror (errno));
       read_file_free (fm);
       return;
     }
