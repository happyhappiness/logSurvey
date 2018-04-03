   return res;
 }
 
+#ifdef ENABLE_IPV6
+static int
+getfamily (int fd)
+{
+  struct sockaddr_storage ss;
+  struct sockaddr *sa = (struct sockaddr *)&ss;
+  socklen_t len = sizeof (ss);
+
+  assert (fd >= 0);
+
+  if (getpeername (fd, sa, &len) < 0)
+    /* Mauro Tortonesi: HOW DO WE HANDLE THIS ERROR? */
+    abort ();
+
+  return sa->sa_family;
+}
+
+/* 
+ * This function sets up a passive data connection with the FTP server.
+ * It is merely a wrapper around ftp_epsv, ftp_lpsv and ftp_pasv.
+ */
+static uerr_t
+ftp_do_pasv (struct rbuf *rbuf, ip_address *addr, unsigned short *port)
+{
+  uerr_t err;
+  int family;
+
+  family = getfamily (rbuf->fd);
+  assert (family == AF_INET || family == AF_INET6);
+
+  /* If our control connection is over IPv6, then we first try EPSV and then 
+   * LPSV if the former is not supported. If the control connection is over 
+   * IPv4, we simply issue the good old PASV request. */
+  if (family == AF_INET6)
+    {
+      if (!opt.server_response)
+        logputs (LOG_VERBOSE, "==> EPSV ... ");
+      err = ftp_epsv (rbuf, addr, port);
+
+      /* If EPSV is not supported try LPSV */
+      if (err == FTPNOPASV)
+        {
+          if (!opt.server_response)
+            logputs (LOG_VERBOSE, "==> LPSV ... ");
+          err = ftp_lpsv (rbuf, addr, port);
+        }
+    }
+  else 
+    {
+      if (!opt.server_response)
+        logputs (LOG_VERBOSE, "==> PASV ... ");
+      err = ftp_pasv (rbuf, addr, port);
+    }
+
+  return err;
+}
+
+/* 
+ * This function sets up an active data connection with the FTP server.
+ * It is merely a wrapper around ftp_eprt, ftp_lprt and ftp_port.
+ */
+static uerr_t
+ftp_do_port (struct rbuf *rbuf)
+{
+  uerr_t err;
+  int family;
+
+  assert (rbuf != NULL);
+  assert (rbuf_initialized_p (rbuf));
+
+  family = getfamily (rbuf->fd);
+  assert (family == AF_INET || family == AF_INET6);
+
+  /* If our control connection is over IPv6, then we first try EPRT and then 
+   * LPRT if the former is not supported. If the control connection is over 
+   * IPv4, we simply issue the good old PORT request. */
+  if (family == AF_INET6)
+    {
+      if (!opt.server_response)
+        logputs (LOG_VERBOSE, "==> EPRT ... ");
+      err = ftp_eprt (rbuf);
+
+      /* If EPRT is not supported try LPRT */
+      if (err == FTPPORTERR)
+        {
+          if (!opt.server_response)
+            logputs (LOG_VERBOSE, "==> LPRT ... ");
+          err = ftp_lprt (rbuf);
+        }
+    }
+  else 
+    {
+      if (!opt.server_response)
+        logputs (LOG_VERBOSE, "==> PORT ... ");
+      err = ftp_port (rbuf);
+    }
+
+  return err;
+}
+#else
+#define ftp_do_pasv ftp_pasv
+#define ftp_do_port ftp_port
+#endif
+
 /* Retrieves a file with denoted parameters through opening an FTP
    connection to the server.  It always closes the data connection,
    and closes the control connection in case of error.  */
