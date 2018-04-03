   if (start > 0)
     {
       if (start >= 1024)
-	logprintf (LOG_VERBOSE, _(", %s (%s) remaining"),
-		   number_to_static_string (size - start),
-		   human_readable (size - start));
+        logprintf (LOG_VERBOSE, _(", %s (%s) remaining"),
+                   number_to_static_string (size - start),
+                   human_readable (size - start));
       else
-	logprintf (LOG_VERBOSE, _(", %s remaining"),
-		   number_to_static_string (size - start));
+        logprintf (LOG_VERBOSE, _(", %s remaining"),
+                   number_to_static_string (size - start));
     }
   logputs (LOG_VERBOSE, !authoritative ? _(" (unauthoritative)\n") : "\n");
 }
