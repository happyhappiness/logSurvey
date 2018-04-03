           }
     }
 
-  if (qop != NULL && strcmp (qop,"auth"))
+  if (qop && strcmp (qop, "auth"))
     {
       logprintf (LOG_NOTQUIET, _("Unsupported quality of protection '%s'.\n"), qop);
-      xfree (qop); /* force freeing mem and return */
+      xfree (qop); /* force freeing mem and continue */
     }
-  else if (algorithm != NULL && strcmp (algorithm,"MD5") && strcmp (algorithm,"MD5-sess"))
+  else if (algorithm && strcmp (algorithm,"MD5") && strcmp (algorithm,"MD5-sess"))
     {
       logprintf (LOG_NOTQUIET, _("Unsupported algorithm '%s'.\n"), algorithm);
-      xfree (qop); /* force freeing mem and return */
+      xfree (algorithm); /* force freeing mem and continue */
     }
 
   if (!realm || !nonce || !user || !passwd || !path || !method)
     {
       *auth_err = ATTRMISSING;
-
-      xfree (realm);
-      xfree (opaque);
-      xfree (nonce);
-      xfree (qop);
-      xfree (algorithm);
-
-      return NULL;
-    }
+      goto cleanup;
+   }
 
   /* Calculate the digest value.  */
   {
