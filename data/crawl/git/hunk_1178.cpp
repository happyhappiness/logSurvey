 	errno = ELOOP;
 	return NULL;
 }
+
+/* A pointer to the ref_store for the main repository: */
+static struct ref_store *main_ref_store;
+
+/* A linked list of ref_stores for submodules: */
+static struct ref_store *submodule_ref_stores;
+
+void base_ref_store_init(struct ref_store *refs,
+			 const struct ref_storage_be *be,
+			 const char *submodule)
+{
+	refs->be = be;
+	if (!submodule) {
+		if (main_ref_store)
+			die("BUG: main_ref_store initialized twice");
+
+		refs->submodule = "";
+		refs->next = NULL;
+		main_ref_store = refs;
+	} else {
+		if (lookup_ref_store(submodule))
+			die("BUG: ref_store for submodule '%s' initialized twice",
+			    submodule);
+
+		refs->submodule = xstrdup(submodule);
+		refs->next = submodule_ref_stores;
+		submodule_ref_stores = refs;
+	}
+}
+
+struct ref_store *ref_store_init(const char *submodule)
+{
+	const char *be_name = "files";
+	struct ref_storage_be *be = find_ref_storage_backend(be_name);
+
+	if (!be)
+		die("BUG: reference backend %s is unknown", be_name);
+
+	if (!submodule || !*submodule)
+		return be->init(NULL);
+	else
+		return be->init(submodule);
+}
+
+struct ref_store *lookup_ref_store(const char *submodule)
+{
+	struct ref_store *refs;
+
+	if (!submodule || !*submodule)
+		return main_ref_store;
+
+	for (refs = submodule_ref_stores; refs; refs = refs->next) {
+		if (!strcmp(submodule, refs->submodule))
+			return refs;
+	}
+
+	return NULL;
+}
+
+struct ref_store *get_ref_store(const char *submodule)
+{
+	struct ref_store *refs;
+
+	if (!submodule || !*submodule) {
+		refs = lookup_ref_store(NULL);
+
+		if (!refs)
+			refs = ref_store_init(NULL);
+	} else {
+		refs = lookup_ref_store(submodule);
+
+		if (!refs) {
+			struct strbuf submodule_sb = STRBUF_INIT;
+
+			strbuf_addstr(&submodule_sb, submodule);
+			if (is_nonbare_repository_dir(&submodule_sb))
+				refs = ref_store_init(submodule);
+			strbuf_release(&submodule_sb);
+		}
+	}
+
+	return refs;
+}
+
+void assert_main_repository(struct ref_store *refs, const char *caller)
+{
+	if (*refs->submodule)
+		die("BUG: %s called for a submodule", caller);
+}
