 	if (!opt->message_given && !buf->len)
 		die(_("no tag message?"));
 
-	strbuf_insert(buf, 0, header_buf, header_len);
+	strbuf_insert(buf, 0, header.buf, header.len);
+	strbuf_release(&header);
 
 	if (build_tag_object(buf, opt->sign, result) < 0) {
 		if (path)