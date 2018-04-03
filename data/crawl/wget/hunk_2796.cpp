      PRINT being the host name we're connecting to.  */
   if (print)
     {
-      const char *txt_addr = pretty_print_address (ip);
+      const char *txt_addr = print_address (ip);
       if (print && 0 != strcmp (print, txt_addr))
 	logprintf (LOG_VERBOSE, _("Connecting to %s|%s|:%d... "),
 		   escnonprint (print), txt_addr, port);
