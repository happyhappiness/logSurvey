 	}
 	if (commit_lock_file(&msg_file) < 0) {
 		rollback_lock_file(&msg_file);
-		return error(_("Error wrapping up %s."), filename);
+		return error(_("Error wrapping up '%s'."), filename);
 	}
 
 	return 0;
