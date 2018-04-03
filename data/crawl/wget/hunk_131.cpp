 
     xfree(in_save);
     iconv_close(cd);
-    DEBUGP (("converted '%s' (%s) -> '%s' (%s)\n", in_org, fromcode, *out, tocode));
+    IF_DEBUG
+    {
+      /* not not print out embedded passwords, in_org might be an URL */
+      if (!strchr(in_org, '@') && !strchr(*out, '@'))
+        debug_logprintf ("converted '%s' (%s) -> '%s' (%s)\n", in_org, fromcode, *out, tocode);
+      else
+        debug_logprintf ("%s: logging suppressed, strings may contain password\n", __func__);
+    }
     return false;
 }
 
