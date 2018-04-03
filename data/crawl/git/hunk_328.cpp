 	return result;
 }
 
-void *fill_tree_descriptor(struct tree_desc *desc, const unsigned char *sha1)
+void *fill_tree_descriptor(struct tree_desc *desc, const struct object_id *oid)
 {
 	unsigned long size = 0;
 	void *buf = NULL;
 
-	if (sha1) {
-		buf = read_object_with_reference(sha1, tree_type, &size, NULL);
+	if (oid) {
+		buf = read_object_with_reference(oid->hash, tree_type, &size,
+						 NULL);
 		if (!buf)
-			die("unable to read tree %s", sha1_to_hex(sha1));
+			die("unable to read tree %s", oid_to_hex(oid));
 	}
 	init_tree_desc(desc, buf, size);
 	return buf;
