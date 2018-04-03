 
   if (! status)
     {
-      error ("unable to open library `%s' to lookup member `%s'",
+      error (NILF, "unable to open library `%s' to lookup member `%s'",
 	     archive, (char *)arg);
       return -1;
     }
