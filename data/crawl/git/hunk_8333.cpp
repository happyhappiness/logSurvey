 	int i;
 	int err = 0;
 
+	if (verbose)
+		fprintf(stderr, "Checking cache tree\n");
+
 	if (0 <= it->entry_count) {
 		struct object *obj = parse_object(it->sha1);
 		if (!obj) {
