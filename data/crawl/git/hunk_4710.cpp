 
 		name = xstrdup(mkpath(fmt, bname.buf));
 		if (!resolve_ref(name, sha1, 1, NULL)) {
-			error("%sbranch '%s' not found.",
+			error(_("%sbranch '%s' not found."),
 					remote, bname.buf);
 			ret = 1;
 			continue;
 		}
 
 		rev = lookup_commit_reference(sha1);
 		if (!rev) {
-			error("Couldn't look up commit object for '%s'", name);
+			error(_("Couldn't look up commit object for '%s'"), name);
 			ret = 1;
 			continue;
 		}
 
 		if (!force && !branch_merged(kinds, bname.buf, rev, head_rev)) {
-			error("The branch '%s' is not fully merged.\n"
+			error(_("The branch '%s' is not fully merged.\n"
 			      "If you are sure you want to delete it, "
-			      "run 'git branch -D %s'.", bname.buf, bname.buf);
+			      "run 'git branch -D %s'."), bname.buf, bname.buf);
 			ret = 1;
 			continue;
 		}
 
 		if (delete_ref(name, sha1, 0)) {
-			error("Error deleting %sbranch '%s'", remote,
+			error(_("Error deleting %sbranch '%s'"), remote,
 			      bname.buf);
 			ret = 1;
 		} else {
