 	 * points to something different than a branch.
 	 */
 	if (!upstream)
-		return error(_("HEAD does not point to a branch"));
+		die(_("HEAD does not point to a branch"));
 	if (!upstream->merge || !upstream->merge[0]->dst) {
 		if (!ref_exists(upstream->refname))
-			return error(_("No such branch: '%s'"), cp);
-		if (!upstream->merge)
-			return error(_("No upstream configured for branch '%s'"),
-				     upstream->name);
-		return error(
+			die(_("No such branch: '%s'"), cp);
+		if (!upstream->merge) {
+			die(_("No upstream configured for branch '%s'"),
+				upstream->name);
+		}
+		die(
 			_("Upstream branch '%s' not stored as a remote-tracking branch"),
 			upstream->merge[0]->src);
 	}
