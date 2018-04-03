     return cookie;
 
   delete_cookie (cookie);
-  if (state == S_ERROR)
-    logprintf (LOG_NOTQUIET, _("Syntax error in Set-Cookie at character `%c'.\n"), c);
-  else
+  if (state != S_ERROR)
     abort ();
-  return NULL;
 
- eof:
-  delete_cookie (cookie);
-  logprintf (LOG_NOTQUIET,
-	     _("Syntax error in Set-Cookie: premature end of string.\n"));
+  if (!silent)
+    logprintf (LOG_NOTQUIET,
+	       _("Syntax error in Set-Cookie: %s at position %d.\n"),
+	       sc, p - sc);
   return NULL;
 }
 
