 			fprintf(stderr, "Skipping account %s@%s, server forbids LOGIN\n", srvc->user, srvc->host);
 			goto bail;
 		}
-		if (!imap->buf.sock.ssl)
-			imap_warn("*** IMAP Warning *** Password is being "
-				  "sent in the clear\n");
 
 		if (srvc->auth_method) {
 			struct imap_cmd_cb cb;
