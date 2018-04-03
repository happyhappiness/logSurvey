 	return clean;
 }
 
+static struct commit *get_ref(const unsigned char *sha1, const char *name)
+{
+	struct object *object;
+
+	object = deref_tag(parse_object(sha1), name, strlen(name));
+	if (!object)
+		return NULL;
+	if (object->type == OBJ_TREE)
+		return make_virtual_commit((struct tree*)object, name);
+	if (object->type != OBJ_COMMIT)
+		return NULL;
+	if (parse_commit((struct commit *)object))
+		return NULL;
+	return (struct commit *)object;
+}
+
+int merge_recursive_generic(const char **base_list,
+		const unsigned char *head_sha1, const char *head_name,
+		const unsigned char *next_sha1, const char *next_name)
+{
+	int clean, index_fd;
+	struct lock_file *lock = xcalloc(1, sizeof(struct lock_file));
+	struct commit *result;
+	struct commit *head_commit = get_ref(head_sha1, head_name);
+	struct commit *next_commit = get_ref(next_sha1, next_name);
+	struct commit_list *ca = NULL;
+
+	if (base_list) {
+		int i;
+		for (i = 0; base_list[i]; ++i) {
+			unsigned char sha[20];
+			struct commit *base;
+			if (get_sha1(base_list[i], sha))
+				return error("Could not resolve ref '%s'",
+								base_list[i]);
+			if (!(base = get_ref(sha, base_list[i])))
+				return error("Could not parse object '%s'",
+								base_list[i]);
+			commit_list_insert(base, &ca);
+		}
+	}
+
+	index_fd = hold_locked_index(lock, 1);
+	clean = merge_recursive(head_commit, next_commit,
+				head_name, next_name, ca, &result);
+	if (active_cache_changed &&
+			(write_cache(index_fd, active_cache, active_nr) ||
+			 commit_locked_index(lock)))
+		return error("Unable to write index.");
+
+	return clean ? 0 : 1;
+}
+
 int merge_recursive_config(const char *var, const char *value, void *cb)
 {
 	if (!strcasecmp(var, "merge.verbosity")) {
