   if (err < 0)
     {
       logprintf (LOG_NOTQUIET, _("%s: No certificate presented by %s.\n"),
-		 severity, escnonprint (host));
+                 severity, escnonprint (host));
       success = false;
       goto out;
     }
