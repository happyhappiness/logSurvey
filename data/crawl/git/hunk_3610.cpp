 {
 	struct tree_desc one;
 	struct tree_desc two;
-	void *one_buf, *two_buf;
+	void *one_buf = fill_tree_desc_strict(&one, hash1);
+	void *two_buf = fill_tree_desc_strict(&two, hash2);
 	int score = 0;
-	enum object_type type;
-	unsigned long size;
 
-	one_buf = read_sha1_file(hash1, &type, &size);
-	if (!one_buf)
-		die("unable to read tree (%s)", sha1_to_hex(hash1));
-	if (type != OBJ_TREE)
-		die("%s is not a tree", sha1_to_hex(hash1));
-	init_tree_desc(&one, one_buf, size);
-	two_buf = read_sha1_file(hash2, &type, &size);
-	if (!two_buf)
-		die("unable to read tree (%s)", sha1_to_hex(hash2));
-	if (type != OBJ_TREE)
-		die("%s is not a tree", sha1_to_hex(hash2));
-	init_tree_desc(&two, two_buf, size);
 	for (;;) {
 		struct name_entry e1, e2;
 		int got_entry_from_one = tree_entry(&one, &e1);
