   if (qop != NULL && strcmp(qop,"auth"))
     {
       logprintf (LOG_NOTQUIET, _("Unsupported quality of protection '%s'.\n"), qop);
-      user = NULL; /* force freeing mem and return */
+      xfree_null (qop); /* force freeing mem and return */
+      qop = NULL;
     }
-
-  if (algorithm != NULL && strcmp (algorithm,"MD5") && strcmp (algorithm,"MD5-sess"))
+  else if (algorithm != NULL && strcmp (algorithm,"MD5") && strcmp (algorithm,"MD5-sess"))
     {
       logprintf (LOG_NOTQUIET, _("Unsupported algorithm '%s'.\n"), algorithm);
-      user = NULL; /* force freeing mem and return */
+      xfree_null (qop); /* force freeing mem and return */
+      qop = NULL;
     }
 
-  if (!realm || !nonce || !user || !passwd || !path || !method)
+  if (!realm || !nonce || !user || !passwd || !path || !method || !qop)
     {
       xfree_null (realm);
       xfree_null (opaque);
       xfree_null (nonce);
       xfree_null (qop);
       xfree_null (algorithm);
+      if (!qop)
+        *auth_err = UNKNOWNATTR;
+      else
+        *auth_err = ATTRMISSING;
       return NULL;
     }
 
