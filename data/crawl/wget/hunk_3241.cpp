 ftp_do_port (struct rbuf *rbuf, int *local_sock)
 {
   uerr_t err;
-  int family;
+  ip_address cip;
 
   assert (rbuf != NULL);
   assert (rbuf_initialized_p (rbuf));
 
-  family = getfamily (rbuf->fd);
-  assert (family == AF_INET || family == AF_INET6);
+  if (!socket_ip_address (RBUF_FD (rbuf), &cip, ENDPOINT_PEER))
+    abort ();
 
   /* If our control connection is over IPv6, then we first try EPRT and then 
    * LPRT if the former is not supported. If the control connection is over 
    * IPv4, we simply issue the good old PORT request. */
-  if (family == AF_INET6)
+  switch (cip.type)
     {
+    case IPV4_ADDRESS:
+      if (!opt.server_response)
+        logputs (LOG_VERBOSE, "==> PORT ... ");
+      err = ftp_port (rbuf, local_sock);
+      break;
+    case IPV6_ADDRESS:
       if (!opt.server_response)
         logputs (LOG_VERBOSE, "==> EPRT ... ");
       err = ftp_eprt (rbuf, local_sock);
