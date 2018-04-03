   return new;
 }
 
+/* Try to decode an ASCII encoded host. Return the new domain in the locale on
+   success or NULL on error. */
+char *idn_decode (char *host)
+{
+  char *new;
+  int ret;
+
+  ret = idna_to_unicode_8zlz (host, &new, 0);
+  if (ret != IDNA_SUCCESS)
+    {
+      logprintf (LOG_VERBOSE, "idn_decode failed (%d): %s\n", ret,
+                 quote (idna_strerror (ret)));
+      return NULL;
+    }
+
+  return new;
+}
+
+
