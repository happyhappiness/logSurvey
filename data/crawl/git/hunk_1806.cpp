 	strbuf_release(&sb);
 	return ret;
 }
-/*
- * Call fn for each reflog in the namespace indicated by name.  name
- * must be empty or end with '/'.  Name will be used as a scratch
- * space, but its contents will be restored before return.
- */
-static int do_for_each_reflog(struct strbuf *name, each_ref_fn fn, void *cb_data)
-{
-	DIR *d = opendir(git_path("logs/%s", name->buf));
-	int retval = 0;
-	struct dirent *de;
-	int oldlen = name->len;
 
-	if (!d)
-		return name->len ? errno : 0;
+struct files_reflog_iterator {
+	struct ref_iterator base;
 
-	while ((de = readdir(d)) != NULL) {
-		struct stat st;
+	struct dir_iterator *dir_iterator;
+	struct object_id oid;
+};
 
-		if (de->d_name[0] == '.')
+static int files_reflog_iterator_advance(struct ref_iterator *ref_iterator)
+{
+	struct files_reflog_iterator *iter =
+		(struct files_reflog_iterator *)ref_iterator;
+	struct dir_iterator *diter = iter->dir_iterator;
+	int ok;
+
+	while ((ok = dir_iterator_advance(diter)) == ITER_OK) {
+		int flags;
+
+		if (!S_ISREG(diter->st.st_mode))
 			continue;
-		if (ends_with(de->d_name, ".lock"))
+		if (diter->basename[0] == '.')
+			continue;
+		if (ends_with(diter->basename, ".lock"))
 			continue;
-		strbuf_addstr(name, de->d_name);
-		if (stat(git_path("logs/%s", name->buf), &st) < 0) {
-			; /* silently ignore */
-		} else {
-			if (S_ISDIR(st.st_mode)) {
-				strbuf_addch(name, '/');
-				retval = do_for_each_reflog(name, fn, cb_data);
-			} else {
-				struct object_id oid;
 
-				if (read_ref_full(name->buf, 0, oid.hash, NULL))
-					error("bad ref for %s", name->buf);
-				else
-					retval = fn(name->buf, &oid, 0, cb_data);
-			}
-			if (retval)
-				break;
+		if (read_ref_full(diter->relative_path, 0,
+				  iter->oid.hash, &flags)) {
+			error("bad ref for %s", diter->path.buf);
+			continue;
 		}
-		strbuf_setlen(name, oldlen);
+
+		iter->base.refname = diter->relative_path;
+		iter->base.oid = &iter->oid;
+		iter->base.flags = flags;
+		return ITER_OK;
 	}
-	closedir(d);
-	return retval;
+
+	iter->dir_iterator = NULL;
+	if (ref_iterator_abort(ref_iterator) == ITER_ERROR)
+		ok = ITER_ERROR;
+	return ok;
+}
+
+static int files_reflog_iterator_peel(struct ref_iterator *ref_iterator,
+				   struct object_id *peeled)
+{
+	die("BUG: ref_iterator_peel() called for reflog_iterator");
+}
+
+static int files_reflog_iterator_abort(struct ref_iterator *ref_iterator)
+{
+	struct files_reflog_iterator *iter =
+		(struct files_reflog_iterator *)ref_iterator;
+	int ok = ITER_DONE;
+
+	if (iter->dir_iterator)
+		ok = dir_iterator_abort(iter->dir_iterator);
+
+	base_ref_iterator_free(ref_iterator);
+	return ok;
+}
+
+static struct ref_iterator_vtable files_reflog_iterator_vtable = {
+	files_reflog_iterator_advance,
+	files_reflog_iterator_peel,
+	files_reflog_iterator_abort
+};
+
+struct ref_iterator *files_reflog_iterator_begin(void)
+{
+	struct files_reflog_iterator *iter = xcalloc(1, sizeof(*iter));
+	struct ref_iterator *ref_iterator = &iter->base;
+
+	base_ref_iterator_init(ref_iterator, &files_reflog_iterator_vtable);
+	iter->dir_iterator = dir_iterator_begin(git_path("logs"));
+	return ref_iterator;
 }
 
 int for_each_reflog(each_ref_fn fn, void *cb_data)
 {
-	int retval;
-	struct strbuf name;
-	strbuf_init(&name, PATH_MAX);
-	retval = do_for_each_reflog(&name, fn, cb_data);
-	strbuf_release(&name);
-	return retval;
+	return do_for_each_ref_iterator(files_reflog_iterator_begin(),
+					fn, cb_data);
 }
 
 static int ref_update_reject_duplicates(struct string_list *refnames,
