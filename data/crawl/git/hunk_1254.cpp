 			      : _("Error deleting branch '%s'"),
 			      bname.buf);
 			ret = 1;
-			continue;
+			goto next;
 		}
 		if (!quiet) {
 			printf(remote_branch
