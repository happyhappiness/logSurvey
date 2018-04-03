   res = make_directory (t);
   if (res != 0)
     logprintf (LOG_NOTQUIET, "%s: %s", t, strerror (errno));
-  free (t);
+  xfree (t);
   return res;
 }
 
