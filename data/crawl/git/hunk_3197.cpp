 {
 	char *branch = xstrndup(branch_buf, len);
 	struct branch *upstream = branch_get(*branch ? branch : NULL);
+	struct strbuf err = STRBUF_INIT;
+	const char *ret;
 
-	/*
-	 * Upstream can be NULL only if branch refers to HEAD and HEAD
-	 * points to something different than a branch.
-	 */
-	if (!upstream)
-		die(_("HEAD does not point to a branch"));
-	if (!upstream->merge || !upstream->merge[0]->dst) {
-		if (!ref_exists(upstream->refname))
-			die(_("No such branch: '%s'"), branch);
-		if (!upstream->merge) {
-			die(_("No upstream configured for branch '%s'"),
-				upstream->name);
-		}
-		die(
-			_("Upstream branch '%s' not stored as a remote-tracking branch"),
-			upstream->merge[0]->src);
-	}
 	free(branch);
 
-	return upstream->merge[0]->dst;
+	ret = branch_get_upstream(upstream, &err);
+	if (!ret)
+		die("%s", err.buf);
+
+	return ret;
 }
 
 static int interpret_upstream_mark(const char *name, int namelen,
