 
   if (*len)
     {
-      logprintf (LOG_VERBOSE, _("Length: %s"), legible (*len));
-      if (restval)
-	logprintf (LOG_VERBOSE, _(" [%s to go]"), legible (*len - restval));
-      logputs (LOG_VERBOSE, "\n");
+      print_length (*len, restval, 1);
       expected_bytes = *len;	/* for get_contents/show_progress */
     }
   else if (expected_bytes)
-    {
-      logprintf (LOG_VERBOSE, _("Length: %s"), legible (expected_bytes));
-      if (restval)
-	logprintf (LOG_VERBOSE, _(" [%s to go]"),
-		   legible (expected_bytes - restval));
-      logputs (LOG_VERBOSE, _(" (unauthoritative)\n"));
-    }
+    print_length (expected_bytes, restval, 0);
 
   /* Get the contents of the document.  */
   flags = 0;
