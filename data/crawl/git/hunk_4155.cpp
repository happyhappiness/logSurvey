 	}
 
 	if (*p == ':') {
-		char *x;
-		oe = find_mark(strtoumax(p + 1, &x, 10));
+		oe = find_mark(parse_mark_ref_space(&p));
 		hashcpy(sha1, oe->idx.sha1);
-		p = x;
-	} else if (!prefixcmp(p, "inline")) {
+	} else if (!prefixcmp(p, "inline ")) {
 		inline_data = 1;
-		p += 6;
+		p += strlen("inline");  /* advance to space */
 	} else {
 		if (get_sha1_hex(p, sha1))
-			die("Invalid SHA1: %s", command_buf.buf);
+			die("Invalid dataref: %s", command_buf.buf);
 		oe = find_object(sha1);
 		p += 40;
+		if (*p != ' ')
+			die("Missing space after SHA1: %s", command_buf.buf);
 	}
-	if (*p++ != ' ')
-		die("Missing space after SHA1: %s", command_buf.buf);
+	assert(*p == ' ');
+	p++;  /* skip space */
 
 	strbuf_reset(&uq);
 	if (!unquote_c_style(&uq, p, &endp)) {
