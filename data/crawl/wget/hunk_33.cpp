     }
   res = make_directory (t);
   if (res != 0)
-    logprintf (LOG_NOTQUIET, "%s: %s", t, strerror (errno));
+    logprintf (LOG_NOTQUIET, "%s: %s\n", t, strerror (errno));
   xfree (t);
   return res;
 }
