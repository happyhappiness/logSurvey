 
 	strbuf_insert(buf, 0, header_buf, header_len);
 
-	if (sign && do_sign(buf) < 0)
-		die("unable to sign the tag");
-	if (write_sha1_file(buf->buf, buf->len, tag_type, result) < 0)
-		die("unable to write tag file");
+	if (build_tag_object(buf, sign, result) < 0) {
+		if (path)
+			fprintf(stderr, "The tag message has been left in %s\n",
+				path);
+		exit(128);
+	}
+	if (path) {
+		unlink(path);
+		free(path);
+	}
 }
 
 struct msg_arg {