 	return refname_match(branch->merge[i]->src, refname);
 }
 
-const char *branch_get_upstream(struct branch *branch)
+__attribute((format (printf,2,3)))
+static const char *error_buf(struct strbuf *err, const char *fmt, ...)
 {
-	if (!branch || !branch->merge || !branch->merge[0])
-		return NULL;
+	if (err) {
+		va_list ap;
+		va_start(ap, fmt);
+		strbuf_vaddf(err, fmt, ap);
+		va_end(ap);
+	}
+	return NULL;
+}
+
+const char *branch_get_upstream(struct branch *branch, struct strbuf *err)
+{
+	if (!branch)
+		return error_buf(err, _("HEAD does not point to a branch"));
+	if (!branch->merge || !branch->merge[0] || !branch->merge[0]->dst) {
+		if (!ref_exists(branch->refname))
+			return error_buf(err, _("no such branch: '%s'"),
+					 branch->name);
+		if (!branch->merge)
+			return error_buf(err,
+					 _("no upstream configured for branch '%s'"),
+					 branch->name);
+		return error_buf(err,
+				 _("upstream branch '%s' not stored as a remote-tracking branch"),
+				 branch->merge[0]->src);
+	}
+
 	return branch->merge[0]->dst;
 }
 
