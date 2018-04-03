 
 		/* Remote branch must be an ancestor of remote HEAD */
 		if (!verify_merge_base(head_sha1, remote_ref->old_sha1)) {
-			return error("The branch '%s' is not a strict subset of your current HEAD.\nIf you are sure you want to delete it, run:\n\t'git http-push -D %s %s'", remote_ref->name, remote->url, pattern);
+			return error("The branch '%s' is not an ancestor "
+				     "of your current HEAD.\n"
+				     "If you are sure you want to delete it,"
+				     " run:\n\t'git http-push -D %s %s'",
+				     remote_ref->name, remote->url, pattern);
 		}
 	}
 
