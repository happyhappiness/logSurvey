 # define FD_TO_SOCKET(X) (X)
 #endif
   gnutls_transport_set_ptr (session, (gnutls_transport_ptr) FD_TO_SOCKET (fd));
+
+  err = 0;
+  switch (opt.secure_protocol)
+    {
+    case secure_protocol_auto:
+      break;
+    case secure_protocol_sslv2:
+    case secure_protocol_sslv3:
+      allowed_protocols[0] = GNUTLS_SSL3;
+      err = gnutls_protocol_set_priority (session, allowed_protocols);
+      break;
+    case secure_protocol_tlsv1:
+      allowed_protocols[0] = GNUTLS_TLS1_0;
+      allowed_protocols[1] = GNUTLS_TLS1_1;
+      allowed_protocols[2] = GNUTLS_TLS1_2;
+      err = gnutls_protocol_set_priority (session, allowed_protocols);
+      break;
+    default:
+      abort ();
+    }
+  if (err < 0)
+    {
+      logprintf (LOG_NOTQUIET, "GnuTLS: %s\n", gnutls_strerror (err));
+      gnutls_deinit (session);
+      return false;
+    }
+
   err = gnutls_handshake (session);
   if (err < 0)
     {
