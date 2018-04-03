 	commit->buffer = buffer;
 }
 
+const void *get_cached_commit_buffer(const struct commit *commit)
+{
+	return commit->buffer;
+}
+
+const void *get_commit_buffer(const struct commit *commit)
+{
+	const void *ret = get_cached_commit_buffer(commit);
+	if (!ret) {
+		enum object_type type;
+		unsigned long size;
+		ret = read_sha1_file(commit->object.sha1, &type, &size);
+		if (!ret)
+			die("cannot read commit object %s",
+			    sha1_to_hex(commit->object.sha1));
+		if (type != OBJ_COMMIT)
+			die("expected commit for %s, got %s",
+			    sha1_to_hex(commit->object.sha1), typename(type));
+	}
+	return ret;
+}
+
+void unuse_commit_buffer(const struct commit *commit, const void *buffer)
+{
+	if (commit->buffer != buffer)
+		free((void *)buffer);
+}
+
 void free_commit_buffer(struct commit *commit)
 {
 	free(commit->buffer);
