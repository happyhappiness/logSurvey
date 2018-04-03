 	if (*p++ != ' ')
 		die("Missing space after SHA1: %s", command_buf.buf);
 
-	p_uq = unquote_c_style(p, &endp);
-	if (p_uq) {
+	strbuf_reset(&uq);
+	if (!unquote_c_style(&uq, p, &endp)) {
 		if (*endp)
 			die("Garbage after path in: %s", command_buf.buf);
-		p = p_uq;
+		p = uq.buf;
 	}
 
 	if (inline_data) {
 		static struct strbuf buf = STRBUF_INIT;
 
-		if (!p_uq)
-			p = p_uq = xstrdup(p);
+		if (p != uq.buf) {
+			strbuf_addstr(&uq, p);
+			p = uq.buf;
+		}
 		read_next_command();
 		cmd_data(&buf);
 		store_object(OBJ_BLOB, &buf, &last_blob, sha1, 0);