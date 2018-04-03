         return true;
     }
 
+    debugs(33, DBG_IMPORTANT, "ERROR: could not create TLS server context for " << conn);
     conn->close();
     return false;
 }
 
 /**
  *
- * \retval 1 on success
- * \retval 0 when needs more data
- * \retval -1 on error
+ * \retval true on success
+ * \retval false when needs more data
+ * \retval false when an error occurred (and closes the TCP connection)
  */
-static int
-Squid_SSL_accept(ConnStateData *conn, PF *callback)
+static bool
+tlsAttemptHandshake(ConnStateData *conn, PF *callback)
 {
+    // TODO: maybe throw instead of just closing the TCP connection.
+    // see https://github.com/squid-cache/squid/pull/81#discussion_r153053278
     int fd = conn->clientConnection->fd;
-    auto ssl = fd_table[fd].ssl.get();
-    int ret;
+    auto session = fd_table[fd].ssl.get();
 
     errno = 0;
-    if ((ret = SSL_accept(ssl)) <= 0) {
-        const int xerrno = errno;
-        const int ssl_error = SSL_get_error(ssl, ret);
 
-        switch (ssl_error) {
+#if USE_OPENSSL
+    const auto ret = SSL_accept(session);
+    if (ret > 0)
+        return true;
 
-        case SSL_ERROR_WANT_READ:
-            Comm::SetSelect(fd, COMM_SELECT_READ, callback, (callback != NULL ? conn : NULL), 0);
-            return 0;
+    const int xerrno = errno;
+    const auto ssl_error = SSL_get_error(session, ret);
 
-        case SSL_ERROR_WANT_WRITE:
-            Comm::SetSelect(fd, COMM_SELECT_WRITE, callback, (callback != NULL ? conn : NULL), 0);
-            return 0;
+    switch (ssl_error) {
 
-        case SSL_ERROR_SYSCALL:
-            if (ret == 0) {
-                debugs(83, 2, "Error negotiating SSL connection on FD " << fd << ": Aborted by client: " << ssl_error);
-            } else {
-                debugs(83, (xerrno == ECONNRESET) ? 1 : 2, "Error negotiating SSL connection on FD " << fd << ": " <<
-                       (xerrno == 0 ? Security::ErrorString(ssl_error) : xstrerr(xerrno)));
-            }
-            return -1;
+    case SSL_ERROR_WANT_READ:
+        Comm::SetSelect(fd, COMM_SELECT_READ, callback, (callback ? conn : nullptr), 0);
+        return false;
 
-        case SSL_ERROR_ZERO_RETURN:
-            debugs(83, DBG_IMPORTANT, "Error negotiating SSL connection on FD " << fd << ": Closed by client");
-            return -1;
+    case SSL_ERROR_WANT_WRITE:
+        Comm::SetSelect(fd, COMM_SELECT_WRITE, callback, (callback ? conn : nullptr), 0);
+        return false;
 
-        default:
-            debugs(83, DBG_IMPORTANT, "Error negotiating SSL connection on FD " <<
-                   fd << ": " << Security::ErrorString(ERR_get_error()) <<
-                   " (" << ssl_error << "/" << ret << ")");
-            return -1;
+    case SSL_ERROR_SYSCALL:
+        if (ret == 0) {
+            debugs(83, 2, "Error negotiating SSL connection on FD " << fd << ": Aborted by client: " << ssl_error);
+        } else {
+            debugs(83, (xerrno == ECONNRESET) ? 1 : 2, "Error negotiating SSL connection on FD " << fd << ": " <<
+                   (xerrno == 0 ? Security::ErrorString(ssl_error) : xstrerr(xerrno)));
         }
+        break;
+
+    case SSL_ERROR_ZERO_RETURN:
+        debugs(83, DBG_IMPORTANT, "Error negotiating SSL connection on FD " << fd << ": Closed by client");
+        break;
+
+    default:
+        debugs(83, DBG_IMPORTANT, "Error negotiating SSL connection on FD " <<
+               fd << ": " << Security::ErrorString(ssl_error) <<
+               " (" << ssl_error << "/" << ret << ")");
+    }
+
+#elif USE_GNUTLS
+
+    const auto x = gnutls_handshake(session);
+    if (x == GNUTLS_E_SUCCESS)
+        return true;
+
+    if (gnutls_error_is_fatal(x)) {
+        debugs(83, 2, "Error negotiating TLS on " << conn->clientConnection << ": Aborted by client: " << Security::ErrorString(x));
 
-        /* NOTREACHED */
+    } else if (x == GNUTLS_E_INTERRUPTED || x == GNUTLS_E_AGAIN) {
+        const auto ioAction = (gnutls_record_get_direction(session)==0 ? COMM_SELECT_READ : COMM_SELECT_WRITE);
+        Comm::SetSelect(fd, ioAction, callback, (callback ? conn : nullptr), 0);
+        return false;
     }
-    return 1;
+
+#else
+    // Performing TLS handshake should never be reachable without a TLS/SSL library.
+    (void)session; // avoid compiler and static analysis complaints
+    fatal("FATAL: HTTPS not supported by this Squid.");
+#endif
+
+    conn->clientConnection->close();
+    return false;
 }
 
 /** negotiate an SSL connection */
 static void
 clientNegotiateSSL(int fd, void *data)
 {
     ConnStateData *conn = (ConnStateData *)data;
-    int ret;
-    if ((ret = Squid_SSL_accept(conn, clientNegotiateSSL)) <= 0) {
-        if (ret < 0) // An error
-            conn->clientConnection->close();
+
+    if (!tlsAttemptHandshake(conn, clientNegotiateSSL))
         return;
-    }
 
     Security::SessionPointer session(fd_table[fd].ssl);
+
+#if USE_OPENSSL
     if (Security::SessionIsResumed(session)) {
         debugs(83, 2, "Session " << SSL_get_session(session.get()) <<
                " reused on FD " << fd << " (" << fd_table[fd].ipaddr <<
