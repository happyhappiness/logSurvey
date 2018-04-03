   if (!silent)
     logprintf (LOG_VERBOSE, _("Resolving %s... "), host);
 
-  /* Host name lookup goes on below.  #### We should implement
-     getaddrinfo_with_timeout and gethostbyname_with_timeout the same
-     way connect.c implements connect_with_timeout.  */
+  /* Host name lookup goes on below. */
 
 #ifdef INET6
   {
