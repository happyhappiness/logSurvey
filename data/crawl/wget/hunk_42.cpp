 char *
 idn_decode (const char *host)
 {
+/*
   char *new;
   int ret;
 
-  ret = idna_to_unicode_8zlz (host, &new, IDNA_FLAGS);
-  if (ret != IDNA_SUCCESS)
+  ret = idn2_register_u8 (NULL, host, (uint8_t **) &new, 0);
+  if (ret != IDN2_OK)
     {
-      logprintf (LOG_VERBOSE, _("idn_decode failed (%d): %s\n"), ret,
-                 quote (idna_strerror (ret)));
+      logprintf (LOG_VERBOSE, _("idn2_register_u8 failed (%d): %s: %s\n"), ret,
+                 quote (idn2_strerror (ret)), host);
       return NULL;
     }
 
   return new;
+*/
+  /* idn2_register_u8() just works label by label.
+   * That is pretty much overhead for just displaying the original ulabels.
+   * To keep at least the debug output format, return a cloned host. */
+  return xstrdup(host);
 }
 
 /* Try to transcode string str from remote encoding to UTF-8. On success, *new
