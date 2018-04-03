  * Create a new submodule ref cache and add it to the internal
  * set of caches.
  */
-static struct files_ref_store *create_ref_store(const char *submodule)
+static struct ref_store *files_ref_store_create(const char *submodule)
 {
-	struct files_ref_store *refs;
-	if (!submodule)
-		submodule = "";
-	FLEX_ALLOC_STR(refs, name, submodule);
-	refs->next = submodule_ref_stores;
-	submodule_ref_stores = refs;
-	return refs;
+	struct files_ref_store *refs = xcalloc(1, sizeof(*refs));
+	struct ref_store *ref_store = (struct ref_store *)refs;
+
+	base_ref_store_init(ref_store, &refs_be_files, submodule);
+
+	return ref_store;
 }
 
-static struct files_ref_store *lookup_ref_store(const char *submodule)
+/*
+ * Downcast ref_store to files_ref_store. Die if ref_store is not a
+ * files_ref_store. If submodule_allowed is not true, then also die if
+ * files_ref_store is for a submodule (i.e., not for the main
+ * repository). caller is used in any necessary error messages.
+ */
+static struct files_ref_store *files_downcast(
+		struct ref_store *ref_store, int submodule_allowed,
+		const char *caller)
 {
-	struct files_ref_store *refs;
+	if (ref_store->be != &refs_be_files)
+		die("BUG: ref_store is type \"%s\" not \"files\" in %s",
+		    ref_store->be->name, caller);
 
-	if (!submodule || !*submodule)
-		return &ref_store;
+	if (!submodule_allowed)
+		assert_main_repository(ref_store, caller);
 
-	for (refs = submodule_ref_stores; refs; refs = refs->next)
-		if (!strcmp(submodule, refs->name))
-			return refs;
-	return NULL;
+	return (struct files_ref_store *)ref_store;
 }
 
 /*
- * Return a pointer to a files_ref_store for the specified submodule. For
- * the main repository, use submodule==NULL; such a call cannot fail.
- * For a submodule, the submodule must exist and be a nonbare
- * repository, otherwise return NULL.
- *
- * The returned structure will be allocated and initialized but not
- * necessarily populated; it should not be freed.
+ * Return a pointer to the reference store for the specified
+ * submodule. For the main repository, use submodule==NULL; such a
+ * call cannot fail. For a submodule, the submodule must exist and be
+ * a nonbare repository, otherwise return NULL. Verify that the
+ * reference store is a files_ref_store, and cast it to that type
+ * before returning it.
  */
-static struct files_ref_store *get_ref_store(const char *submodule)
+static struct files_ref_store *get_files_ref_store(const char *submodule,
+						   const char *caller)
 {
-	struct files_ref_store *refs = lookup_ref_store(submodule);
+	struct ref_store *refs = get_ref_store(submodule);
 
-	if (!refs) {
-		struct strbuf submodule_sb = STRBUF_INIT;
-
-		strbuf_addstr(&submodule_sb, submodule);
-		if (is_nonbare_repository_dir(&submodule_sb))
-			refs = create_ref_store(submodule);
-		strbuf_release(&submodule_sb);
-	}
-
-	return refs;
+	return refs ? files_downcast(refs, 1, caller) : NULL;
 }
 
 /* The length of a peeled reference line in packed-refs, including EOL: */
