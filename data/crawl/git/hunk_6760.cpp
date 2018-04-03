 	return new;
 }
 
+static void record_intent_to_add(struct cache_entry *ce)
+{
+	unsigned char sha1[20];
+	if (write_sha1_file("", 0, blob_type, sha1))
+		die("cannot create an empty blob in the object database");
+	hashcpy(ce->sha1, sha1);
+}
+
 int add_to_index(struct index_state *istate, const char *path, struct stat *st, int flags)
 {
 	int size, namelen, was_same;
