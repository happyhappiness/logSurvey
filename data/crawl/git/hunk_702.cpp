 static int for_each_replace_name(const char **argv, each_replace_name_fn fn)
 {
 	const char **p, *full_hex;
-	char ref[PATH_MAX];
+	struct strbuf ref = STRBUF_INIT;
+	size_t base_len;
 	int had_error = 0;
 	struct object_id oid;
 
+	strbuf_addstr(&ref, git_replace_ref_base);
+	base_len = ref.len;
+
 	for (p = argv; *p; p++) {
 		if (get_oid(*p, &oid)) {
 			error("Failed to resolve '%s' as a valid ref.", *p);
 			had_error = 1;
 			continue;
 		}
-		full_hex = oid_to_hex(&oid);
-		snprintf(ref, sizeof(ref), "%s%s", git_replace_ref_base, full_hex);
-		/* read_ref() may reuse the buffer */
-		full_hex = ref + strlen(git_replace_ref_base);
-		if (read_ref(ref, oid.hash)) {
+
+		strbuf_setlen(&ref, base_len);
+		strbuf_addstr(&ref, oid_to_hex(&oid));
+		full_hex = ref.buf + base_len;
+
+		if (read_ref(ref.buf, oid.hash)) {
 			error("replace ref '%s' not found.", full_hex);
 			had_error = 1;
 			continue;
 		}
-		if (fn(full_hex, ref, &oid))
+		if (fn(full_hex, ref.buf, &oid))
 			had_error = 1;
 	}
 	return had_error;
