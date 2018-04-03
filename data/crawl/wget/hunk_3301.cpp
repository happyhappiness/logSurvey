   return ctx.result;
 }
 
-/* A kludge, but still better than passing the host name all the way
-   to connect_to_one.  */
-static const char *connection_host_name;
-
-void
-set_connection_host_name (const char *host)
-{
-  if (host)
-    assert (connection_host_name == NULL);
-  else
-    assert (connection_host_name != NULL);
-
-  connection_host_name = host;
-}
+/* Connect to a remote endpoint whose IP address is known.  */
 
-/* Connect to a remote host whose address has been resolved. */
 int
-connect_to_one (ip_address *addr, unsigned short port, int silent)
+connect_to_ip (const ip_address *ip, int port, const char *print)
 {
   struct sockaddr_storage ss;
   struct sockaddr *sa = (struct sockaddr *)&ss;
   int sock, save_errno;
 
-  /* Set port and protocol */
-  sockaddr_set_address (sa, port, addr);
-
-  if (!silent)
+  /* If PRINT is non-NULL, print the "Connecting to..." line, with
+     PRINT being the host name we're connecting to.  */
+  if (print)
     {
-      const char *pretty_addr = pretty_print_address (addr);
-      if (connection_host_name
-	  && 0 != strcmp (connection_host_name, pretty_addr))
-	logprintf (LOG_VERBOSE, _("Connecting to %s[%s]:%hu... "),
-		   connection_host_name, pretty_addr, port);
+      const char *txt_addr = pretty_print_address (ip);
+      if (print && 0 != strcmp (print, txt_addr))
+	logprintf (LOG_VERBOSE,
+		   _("Connecting to %s{%s}:%d... "), print, txt_addr, port);
       else
-	logprintf (LOG_VERBOSE, _("Connecting to %s:%hu... "),
-		   pretty_addr, port);
+	logprintf (LOG_VERBOSE, _("Connecting to %s:%d... "), txt_addr, port);
     }
 
+  /* Store the sockaddr info to SA.  */
+  sockaddr_set_data (sa, ip, port);
+
   /* Create the socket of the family appropriate for the address.  */
   sock = socket (sa->sa_family, SOCK_STREAM, 0);
   if (sock < 0)
     goto out;
 
   /* For very small rate limits, set the buffer size (and hence,
-     hopefully, the size of the kernel window) to the size of the
-     limit.  That way we don't sleep for more than 1s between network
-     reads.  */
+     hopefully, the kernel's TCP window size) to the per-second limit.
+     That way we should never have to sleep for more than 1s between
+     network reads.  */
   if (opt.limit_rate && opt.limit_rate < 8192)
     {
       int bufsize = opt.limit_rate;
       if (bufsize < 512)
-	bufsize = 512;
+	bufsize = 512;		/* avoid pathologically small values */
 #ifdef SO_RCVBUF
       setsockopt (sock, SOL_SOCKET, SO_RCVBUF,
-		  (char *)&bufsize, sizeof (bufsize));
+		  (void *)&bufsize, (socklen_t)sizeof (bufsize));
 #endif
-      /* When we add opt.limit_rate support for writing, as with
-	 `--post-file', also set SO_SNDBUF here.  */
+      /* When we add limit_rate support for writing, which is useful
+	 for POST, we should also set SO_SNDBUF here.  */
     }
 
   if (opt.bind_address)
     {
-      /* Bind the client side to the requested address. */
-      ip_address bind_address;
-      if (resolve_bind_address (0, &bind_address))
-        {
-          struct sockaddr_storage bss;
-          struct sockaddr *bsa = (struct sockaddr *)&bss;
-          sockaddr_set_address (bsa, 0, &bind_address);
-          if (bind (sock, bsa, sockaddr_len (bsa)))
+      /* Bind the client side of the socket to the requested
+	 address.  */
+      struct sockaddr_storage bind_ss;
+      struct sockaddr *bind_sa = (struct sockaddr *)&bind_ss;
+      if (resolve_bind_address (opt.bind_address, bind_sa, 0))
+	{
+          if (bind (sock, bind_sa, sockaddr_size (bind_sa)) < 0)
 	    {
 	      CLOSE (sock);
 	      sock = -1;
