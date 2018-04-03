   statcode = -1;
   *dt &= ~RETROKF;
 
-  DEBUGP (("\n---response begin---\n"));
-
-  head = fd_read_head (sock);
+  head = fd_read_http_head (sock);
   if (!head)
     {
       logputs (LOG_VERBOSE, "\n");
