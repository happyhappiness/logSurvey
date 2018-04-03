 			     const void *cb_data)
 {
 	const char **p;
-	char ref[PATH_MAX];
+	struct strbuf ref = STRBUF_INIT;
 	int had_error = 0;
 	unsigned char sha1[20];
 
 	for (p = argv; *p; p++) {
-		if (snprintf(ref, sizeof(ref), "refs/tags/%s", *p)
-					>= sizeof(ref)) {
-			error(_("tag name too long: %.*s..."), 50, *p);
-			had_error = 1;
-			continue;
-		}
-		if (read_ref(ref, sha1)) {
+		strbuf_reset(&ref);
+		strbuf_addf(&ref, "refs/tags/%s", *p);
+		if (read_ref(ref.buf, sha1)) {
 			error(_("tag '%s' not found."), *p);
 			had_error = 1;
 			continue;
 		}
-		if (fn(*p, ref, sha1, cb_data))
+		if (fn(*p, ref.buf, sha1, cb_data))
 			had_error = 1;
 	}
+	strbuf_release(&ref);
 	return had_error;
 }
 