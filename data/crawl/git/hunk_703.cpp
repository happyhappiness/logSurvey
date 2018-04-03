 
 static void check_ref_valid(struct object_id *object,
 			    struct object_id *prev,
-			    char *ref,
-			    int ref_size,
+			    struct strbuf *ref,
 			    int force)
 {
-	if (snprintf(ref, ref_size,
-		     "%s%s", git_replace_ref_base,
-		     oid_to_hex(object)) > ref_size - 1)
-		die("replace ref name too long: %.*s...", 50, ref);
-	if (check_refname_format(ref, 0))
-		die("'%s' is not a valid ref name.", ref);
-
-	if (read_ref(ref, prev->hash))
+	strbuf_reset(ref);
+	strbuf_addf(ref, "%s%s", git_replace_ref_base, oid_to_hex(object));
+	if (check_refname_format(ref->buf, 0))
+		die("'%s' is not a valid ref name.", ref->buf);
+
+	if (read_ref(ref->buf, prev->hash))
 		oidclr(prev);
 	else if (!force)
-		die("replace ref '%s' already exists", ref);
+		die("replace ref '%s' already exists", ref->buf);
 }
 
 static int replace_object_oid(const char *object_ref,
