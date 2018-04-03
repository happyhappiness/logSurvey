 		    branch_name, comment_line_char);
 	if (write_file_gently(git_path(edit_description), "%s", buf.buf)) {
 		strbuf_release(&buf);
-		return error(_("could not write branch description template: %s"),
-			     strerror(errno));
+		return error_errno(_("could not write branch description template"));
 	}
 	strbuf_reset(&buf);
 	if (launch_editor(git_path(edit_description), &buf, NULL)) {