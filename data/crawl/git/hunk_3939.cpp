 		if (fd < 0)
 			die_errno(_("could not create file '%s'"), path);
 
-		if (!is_null_sha1(prev))
+		if (!is_null_sha1(prev)) {
 			write_tag_body(fd, prev);
-		else if (opt->cleanup_mode == CLEANUP_ALL)
-			write_or_die(fd, _(tag_template),
-					strlen(_(tag_template)));
-		else
-			write_or_die(fd, _(tag_template_nocleanup),
-					strlen(_(tag_template_nocleanup)));
+		} else {
+			struct strbuf buf = STRBUF_INIT;
+			strbuf_addch(&buf, '\n');
+			if (opt->cleanup_mode == CLEANUP_ALL)
+				strbuf_commented_addf(&buf, _(tag_template), comment_line_char);
+			else
+				strbuf_commented_addf(&buf, _(tag_template_nocleanup), comment_line_char);
+			write_or_die(fd, buf.buf, buf.len);
+			strbuf_release(&buf);
+		}
 		close(fd);
 
 		if (launch_editor(path, buf, NULL)) {
