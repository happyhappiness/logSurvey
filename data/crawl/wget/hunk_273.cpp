       user = NULL; /* force freeing mem and return */
     }
 
+  if (algorithm != NULL && strcmp (algorithm,"MD5") && strcmp (algorithm,"MD5-sess"))
+    {
+      logprintf (LOG_NOTQUIET, _("Unsupported algorithm '%s'.\n"), algorithm);
+      user = NULL; /* force freeing mem and return */
+    }
+
   if (!realm || !nonce || !user || !passwd || !path || !method)
     {
       xfree_null (realm);
       xfree_null (opaque);
       xfree_null (nonce);
       xfree_null (qop);
+      xfree_null (algorithm);
       return NULL;
     }
 
