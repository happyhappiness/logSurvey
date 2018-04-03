 	/* cat-blob SP <object> LF */
 	p = command_buf.buf + strlen("cat-blob ");
 	if (*p == ':') {
-		char *x;
-		oe = find_mark(strtoumax(p + 1, &x, 10));
-		if (x == p + 1)
-			die("Invalid mark: %s", command_buf.buf);
+		oe = find_mark(parse_mark_ref_eol(p));
 		if (!oe)
 			die("Unknown mark: %s", command_buf.buf);
-		if (*x)
-			die("Garbage after mark: %s", command_buf.buf);
 		hashcpy(sha1, oe->idx.sha1);
 	} else {
 		if (get_sha1_hex(p, sha1))
-			die("Invalid SHA1: %s", command_buf.buf);
+			die("Invalid dataref: %s", command_buf.buf);
 		if (p[40])
 			die("Garbage after SHA1: %s", command_buf.buf);
 		oe = find_object(sha1);
