 				goto bail;
 			}
 		} else {
+			if (CAP(NOLOGIN)) {
+				fprintf(stderr, "Skipping account %s@%s, server forbids LOGIN\n",
+					srvc->user, srvc->host);
+				goto bail;
+			}
 			if (!imap->buf.sock.ssl)
 				imap_warn("*** IMAP Warning *** Password is being "
 					  "sent in the clear\n");