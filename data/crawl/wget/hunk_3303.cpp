     {
       if (!opt.server_response)
         logputs (LOG_VERBOSE, "==> EPRT ... ");
-      err = ftp_eprt (rbuf);
+      err = ftp_eprt (rbuf, local_sock);
 
       /* If EPRT is not supported try LPRT */
       if (err == FTPPORTERR)
         {
           if (!opt.server_response)
             logputs (LOG_VERBOSE, "==> LPRT ... ");
-          err = ftp_lprt (rbuf);
+          err = ftp_lprt (rbuf, local_sock);
         }
     }
   else 
     {
       if (!opt.server_response)
         logputs (LOG_VERBOSE, "==> PORT ... ");
-      err = ftp_port (rbuf);
+      err = ftp_port (rbuf, local_sock);
     }
 
   return err;
 }
 #else
-#define ftp_do_pasv ftp_pasv
-#define ftp_do_port ftp_port
+
+static uerr_t
+ftp_do_pasv (struct rbuf *rbuf, ip_address *addr, int *port)
+{
+  if (!opt.server_response)
+    logputs (LOG_VERBOSE, "==> PASV ... ");
+  return ftp_pasv (rbuf, addr, port);
+}
+
+static uerr_t
+ftp_do_port (struct rbuf *rbuf, int *local_sock)
+{
+  if (!opt.server_response)
+    logputs (LOG_VERBOSE, "==> PORT ... ");
+  return ftp_port (rbuf, local_sock);
+}
 #endif
 
 /* Retrieves a file with denoted parameters through opening an FTP
