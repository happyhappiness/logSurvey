 	return sort_ref_list(list);
 }
 
+struct warn_if_dangling_data {
+	const char *refname;
+	const char *msg_fmt;
+};
+
+static int warn_if_dangling_symref(const char *refname, const unsigned char *sha1,
+				   int flags, void *cb_data)
+{
+	struct warn_if_dangling_data *d = cb_data;
+	const char *resolves_to;
+	unsigned char junk[20];
+
+	if (!(flags & REF_ISSYMREF))
+		return 0;
+
+	resolves_to = resolve_ref(refname, junk, 0, NULL);
+	if (!resolves_to || strcmp(resolves_to, d->refname))
+		return 0;
+
+	printf(d->msg_fmt, refname);
+	return 0;
+}
+
+void warn_dangling_symref(const char *msg_fmt, const char *refname)
+{
+	struct warn_if_dangling_data data = { refname, msg_fmt };
+	for_each_rawref(warn_if_dangling_symref, &data);
+}
+
 static struct ref_list *get_loose_refs(void)
 {
 	if (!cached_refs.did_loose) {
