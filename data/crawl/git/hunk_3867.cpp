 		return -1;
 	}
 
+	if (verify) {
+		/* make sure the hostname matches that of the certificate */
+		cert = SSL_get_peer_certificate(sock->ssl);
+		if (!cert)
+			return error("unable to get peer certificate.");
+		if (verify_hostname(cert, server.host) < 0)
+			return -1;
+	}
+
 	return 0;
-#endif
 }
+#endif
 
 static int socket_read(struct imap_socket *sock, char *buf, int len)
 {