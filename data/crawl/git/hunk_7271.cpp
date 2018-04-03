 	return pos;
 }
 
+static int different_name(struct cache_entry *ce, struct cache_entry *alias)
+{
+	int len = ce_namelen(ce);
+	return ce_namelen(alias) != len || memcmp(ce->name, alias->name, len);
+}
+
+/*
+ * If we add a filename that aliases in the cache, we will use the
+ * name that we already have - but we don't want to update the same
+ * alias twice, because that implies that there were actually two
+ * different files with aliasing names!
+ *
+ * So we use the CE_ADDED flag to verify that the alias was an old
+ * one before we accept it as
+ */
+static struct cache_entry *create_alias_ce(struct cache_entry *ce, struct cache_entry *alias)
+{
+	int len;
+	struct cache_entry *new;
+
+	if (alias->ce_flags & CE_ADDED)
+		die("Will not add file alias '%s' ('%s' already exists in index)", ce->name, alias->name);
+
+	/* Ok, create the new entry using the name of the existing alias */
+	len = ce_namelen(alias);
+	new = xcalloc(1, cache_entry_size(len));
+	memcpy(new->name, alias->name, len);
+	copy_cache_entry(new, ce);
+	free(ce);
+	return new;
+}
+
 int add_file_to_index(struct index_state *istate, const char *path, int verbose)
 {
 	int size, namelen;
