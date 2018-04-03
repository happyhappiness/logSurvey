 	   (unsigned long) ssl));
   return 1;
 
- err:
+ error:
   print_errors ();
   if (ssl)
     SSL_free (ssl);
   return 0;
 }
+
+/* Check that the identity of the remote host, as presented by its
+   server certificate, corresponds to HOST, which is the host name the
+   user thinks he's connecting to.  This assumes that FD has been
+   connected to an SSL context using ssl_connect.  Return 1 if the
+   identity checks out, 0 otherwise.
+
+   If opt.check_cert is 0, this always returns 1, but still warns the
+   user about the mismatches, if any.  */
+
+int
+ssl_check_server_identity (int fd, const char *host)
+{
+  X509 *peer = NULL;
+  char peer_CN[256];
+  long vresult;
+  int retval;
+
+  /* If the user has specified --no-check-cert, we still want to warn
+     him about problems with the server's certificate.  */
+  const char *severity = opt.check_cert ? _("ERROR") : _("WARNING");
+
+  SSL *ssl = (SSL *) fd_transport_context (fd);
+  assert (ssl != NULL);
+
+  peer = SSL_get_peer_certificate (ssl);
+  if (!peer)
+    {
+      logprintf (LOG_NOTQUIET, _("%s: No certificate presented by %s.\n"),
+		 severity, escnonprint (host));
+      retval = 0;
+      goto out;
+    }
+
+  vresult = SSL_get_verify_result (ssl);
+  if (vresult != X509_V_OK)
+    {
+      logprintf (LOG_NOTQUIET,
+		 _("%s: Certificate verification error for %s: %s\n"),
+		 severity, escnonprint (host),
+		 X509_verify_cert_error_string (vresult));
+      retval = 0;
+      goto out;
+    }
+
+  /* Check that the common name matches HOST.
+
+     #### This should use dNSName if available; according to rfc2818:
+     "If a subjectAltName extension of type dNSName is present, that
+     MUST be used as the identity."  */
+
+  peer_CN[0] = '\0';
+  X509_NAME_get_text_by_NID (X509_get_subject_name (peer),
+			     NID_commonName, peer_CN, sizeof (peer_CN));
+  if (0 != strcasecmp (peer_CN, host))
+    {
+      logprintf (LOG_NOTQUIET, _("\
+%s: certificate common name `%s' doesn't match requested host name `%s'.\n"),
+		 severity, escnonprint (peer_CN), escnonprint (host));
+      retval = 0;
+      goto out;
+    }
+
+  /* The certificate was found, verified, and matched HOST. */
+  retval = 1;
+
+ out:
+  if (peer)
+    X509_free (peer);
+
+  /* Allow --no-check-cert to disable certificate checking. */
+  return opt.check_cert ? retval : 1;
+}
+
