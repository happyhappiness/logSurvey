 
   if (! status)
     {
-      error (NILF, "unable to open library `%s' to lookup member `%s'",
+      error (NILF, _("unable to open library `%s' to lookup member `%s'"),
 	     archive, (char *)arg);
       return -1;
     }
