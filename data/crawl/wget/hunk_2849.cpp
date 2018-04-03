     {
       logprintf (LOG_NOTQUIET, _("%s: No certificate presented by %s.\n"),
 		 severity, escnonprint (host));
-      success = 0;
+      success = false;
       goto no_cert;		/* must bail out since CERT is NULL */
     }
 
