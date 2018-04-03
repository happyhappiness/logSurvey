 	return 0;
 }
 
+struct has_commit_data {
+	int result;
+	const char *path;
+};
+
 static int check_has_commit(const struct object_id *oid, void *data)
 {
-	int *has_commit = data;
+	struct has_commit_data *cb = data;
 
-	if (!lookup_commit_reference(oid))
-		*has_commit = 0;
+	enum object_type type = sha1_object_info(oid->hash, NULL);
 
-	return 0;
+	switch (type) {
+	case OBJ_COMMIT:
+		return 0;
+	case OBJ_BAD:
+		/*
+		 * Object is missing or invalid. If invalid, an error message
+		 * has already been printed.
+		 */
+		cb->result = 0;
+		return 0;
+	default:
+		die(_("submodule entry '%s' (%s) is a %s, not a commit"),
+		    cb->path, oid_to_hex(oid), typename(type));
+	}
 }
 
 static int submodule_has_commits(const char *path, struct oid_array *commits)
 {
-	int has_commit = 1;
+	struct has_commit_data has_commit = { 1, path };
 
 	/*
 	 * Perform a cheap, but incorrect check for the existence of 'commits'.
