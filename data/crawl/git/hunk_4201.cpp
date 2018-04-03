 			die_errno("unable to relay credential");
 	}
 
-	if (send_request(socket, &buf) < 0 && (flags & FLAG_SPAWN)) {
-		spawn_daemon(socket);
-		if (send_request(socket, &buf) < 0)
+	if (send_request(socket, &buf) < 0) {
+		if (errno != ENOENT)
 			die_errno("unable to connect to cache daemon");
+		if (flags & FLAG_SPAWN) {
+			spawn_daemon(socket);
+			if (send_request(socket, &buf) < 0)
+				die_errno("unable to connect to cache daemon");
+		}
 	}
 	strbuf_release(&buf);
 }