 	return (struct oid_array *) item->util;
 }
 
+struct collect_changed_submodules_cb_data {
+	struct string_list *changed;
+	const struct object_id *commit_oid;
+};
+
+/*
+ * this would normally be two functions: default_name_from_path() and
+ * path_from_default_name(). Since the default name is the same as
+ * the submodule path we can get away with just one function which only
+ * checks whether there is a submodule in the working directory at that
+ * location.
+ */
+static const char *default_name_or_path(const char *path_or_name)
+{
+	int error_code;
+
+	if (!is_submodule_populated_gently(path_or_name, &error_code))
+		return NULL;
+
+	return path_or_name;
+}
+
 static void collect_changed_submodules_cb(struct diff_queue_struct *q,
 					  struct diff_options *options,
 					  void *data)
 {
+	struct collect_changed_submodules_cb_data *me = data;
+	struct string_list *changed = me->changed;
+	const struct object_id *commit_oid = me->commit_oid;
 	int i;
-	struct string_list *changed = data;
 
 	for (i = 0; i < q->nr; i++) {
 		struct diff_filepair *p = q->queue[i];
 		struct oid_array *commits;
+		const struct submodule *submodule;
+		const char *name;
+
 		if (!S_ISGITLINK(p->two->mode))
 			continue;
 
-		if (S_ISGITLINK(p->one->mode)) {
-			/*
-			 * NEEDSWORK: We should honor the name configured in
-			 * the .gitmodules file of the commit we are examining
-			 * here to be able to correctly follow submodules
-			 * being moved around.
-			 */
-			commits = submodule_commits(changed, p->two->path);
-			oid_array_append(commits, &p->two->oid);
-		} else {
-			/* Submodule is new or was moved here */
-			/*
-			 * NEEDSWORK: When the .git directories of submodules
-			 * live inside the superprojects .git directory some
-			 * day we should fetch new submodules directly into
-			 * that location too when config or options request
-			 * that so they can be checked out from there.
-			 */
-			continue;
+		submodule = submodule_from_path(commit_oid, p->two->path);
+		if (submodule)
+			name = submodule->name;
+		else {
+			name = default_name_or_path(p->two->path);
+			/* make sure name does not collide with existing one */
+			submodule = submodule_from_name(commit_oid, name);
+			if (submodule) {
+				warning("Submodule in commit %s at path: "
+					"'%s' collides with a submodule named "
+					"the same. Skipping it.",
+					oid_to_hex(commit_oid), name);
+				name = NULL;
+			}
 		}
+
+		if (!name)
+			continue;
+
+		commits = submodule_commits(changed, name);
+		oid_array_append(commits, &p->two->oid);
 	}
 }
 
