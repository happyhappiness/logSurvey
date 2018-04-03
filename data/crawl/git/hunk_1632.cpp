 	if (status) {
 		if (status == SCLD_EXISTS)
 			/* something else exists */
-			return error(msg, path, _(": perhaps a D/F conflict?"));
-		return error(msg, path, "");
+			return err(o, msg, path, _(": perhaps a D/F conflict?"));
+		return err(o, msg, path, "");
 	}
 
 	/*
 	 * Do not unlink a file in the work tree if we are not
 	 * tracking it.
 	 */
 	if (would_lose_untracked(path))
-		return error(_("refusing to lose untracked file at '%s'"),
+		return err(o, _("refusing to lose untracked file at '%s'"),
 			     path);
 
 	/* Successful unlink is good.. */
