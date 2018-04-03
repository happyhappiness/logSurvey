 	enum object_type type;
 	char *buf;
 	struct object *object;
+	int eaten;
 
 	if (no_data)
 		return;
 
 	if (is_null_sha1(sha1))
 		return;
 
-	object = parse_object(sha1);
-	if (!object)
-		die ("Could not read blob %s", sha1_to_hex(sha1));
-
-	if (object->flags & SHOWN)
+	object = lookup_object(sha1);
+	if (object && object->flags & SHOWN)
 		return;
 
 	buf = read_sha1_file(sha1, &type, &size);
 	if (!buf)
 		die ("Could not read blob %s", sha1_to_hex(sha1));
+	if (check_sha1_signature(sha1, buf, size, typename(type)) < 0)
+		die("sha1 mismatch in blob %s", sha1_to_hex(sha1));
+	object = parse_object_buffer(sha1, type, size, buf, &eaten);
+	if (!object)
+		die("Could not read blob %s", sha1_to_hex(sha1));
 
 	mark_next_object(object);
 
