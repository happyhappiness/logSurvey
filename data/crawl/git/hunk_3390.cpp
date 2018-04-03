 	if (len > 0)
 		return reinterpret(name, namelen, len, buf);
 
-	tmp_len = upstream_mark(cp, namelen - (cp - name));
-	if (!tmp_len)
-		return -1;
+	len = interpret_upstream_mark(name, namelen, cp - name, buf);
+	if (len > 0)
+		return len;
 
-	len = cp + tmp_len - name;
-	cp = xstrndup(name, cp - name);
-	upstream = branch_get(*cp ? cp : NULL);
-	/*
-	 * Upstream can be NULL only if cp refers to HEAD and HEAD
-	 * points to something different than a branch.
-	 */
-	if (!upstream)
-		die(_("HEAD does not point to a branch"));
-	if (!upstream->merge || !upstream->merge[0]->dst) {
-		if (!ref_exists(upstream->refname))
-			die(_("No such branch: '%s'"), cp);
-		if (!upstream->merge) {
-			die(_("No upstream configured for branch '%s'"),
-				upstream->name);
-		}
-		die(
-			_("Upstream branch '%s' not stored as a remote-tracking branch"),
-			upstream->merge[0]->src);
-	}
-	free(cp);
-	cp = shorten_unambiguous_ref(upstream->merge[0]->dst, 0);
-	strbuf_reset(buf);
-	strbuf_addstr(buf, cp);
-	free(cp);
-	return len;
+	return -1;
 }
 
 int strbuf_branchname(struct strbuf *sb, const char *name)