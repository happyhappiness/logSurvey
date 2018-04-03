 	    continue;
 	} else if (x == 0) {
 	    assert(Requests != NULL);
-	    fprintf(stderr, "TIMEOUT waiting for %s\n", Requests->url);
+	    fprintf(stderr, "TIMEOUT %s; %d, %d\n", Requests->url,
+		++timeouts, noutstanding);
 	    continue;
 	}
 	if (FD_ISSET(pconn_fd, &R)) {
+	    timeouts = 0;
 	    if (read_reply(pconn_fd) != 0)
 		pconn_fd = -1;
 	}