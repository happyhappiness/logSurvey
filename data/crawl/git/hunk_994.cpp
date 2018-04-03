 	strbuf_addf(&buf, "%s\n", head);
 	if (write_in_full(fd, buf.buf, buf.len) < 0) {
 		rollback_lock_file(&head_lock);
-		return error_errno(_("Could not write to %s"),
+		return error_errno(_("Could not write to '%s'"),
 				   git_path_head_file());
 	}
 	if (commit_lock_file(&head_lock) < 0) {
 		rollback_lock_file(&head_lock);
-		return error(_("Error wrapping up %s."), git_path_head_file());
+		return error(_("Error wrapping up '%s'."), git_path_head_file());
 	}
 	return 0;
 }
