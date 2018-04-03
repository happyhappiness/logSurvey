 #endif  /* HAVE_DMALLOC_H */
 
 char *
-savestring (const char *str, unsigned int length)
+xstrndup (const char *str, unsigned int length)
 {
-  char *out = xmalloc (length + 1);
-  if (length > 0)
-    memcpy (out, str, length);
-  out[length] = '\0';
-  return out;
+  char *result;
+
+#ifdef HAVE_STRNDUP
+  result = strndup (str, length);
+  if (result == 0)
+    fatal (NILF, _("virtual memory exhausted"));
+#else
+  result = xmalloc (length + 1);
+  strncpy (result, str, length);
+  result[length] = '\0';
+#endif
+
+  return result;
 }
 
 
