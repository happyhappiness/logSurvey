 		{
 			fprintf (stderr, "Cannot compile regex %s: %i/%s",
 					entry, rcompile, regerr);
-			syslog (LOG_ERR, "Cannot compile regex %s: %i/%s",
+			ERROR ("Cannot compile regex %s: %i/%s",
 					entry, rcompile, regerr);
 		}
 		else
 		{
 			fprintf (stderr, "Cannot compile regex %s: %i",
 					entry, rcompile);
-			syslog (LOG_ERR, "Cannot compile regex %s: %i",
+			ERROR ("Cannot compile regex %s: %i",
 					entry, rcompile);
 		}
 
