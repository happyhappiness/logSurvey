 {
 	struct object *obj;
 
+	if (verbose)
+		fprintf(stderr, "Checking reflog %s->%s\n",
+			sha1_to_hex(osha1), sha1_to_hex(nsha1));
+
 	if (!is_null_sha1(osha1)) {
 		obj = lookup_object(osha1);
 		if (obj) {
