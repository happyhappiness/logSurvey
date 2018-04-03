   if (!cert)
     {
       logprintf (LOG_NOTQUIET, _("%s: No certificate presented by %s.\n"),
-		 severity, escnonprint (host));
+                 severity, escnonprint (host));
       success = false;
-      goto no_cert;		/* must bail out since CERT is NULL */
+      goto no_cert;             /* must bail out since CERT is NULL */
     }
 
   IF_DEBUG
