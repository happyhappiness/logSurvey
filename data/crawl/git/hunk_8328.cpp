 {
 	struct object *tagged = tag->tagged;
 
+	if (verbose)
+		fprintf(stderr, "Checking tag %s\n",
+			sha1_to_hex(tag->object.sha1));
+
 	if (!tagged) {
 		return objerror(&tag->object, "could not load tagged object");
 	}
