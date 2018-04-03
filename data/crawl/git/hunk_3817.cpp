 
 	fprintf(cb->refs_file, "%s %s\n", sha1_to_hex(sha1), path);
 	if (is_tag_ref) {
-		struct object *o = parse_object(sha1);
+		struct object *o = parse_object_or_die(sha1, path);
 		if (o->type == OBJ_TAG) {
 			o = deref_tag(o, path, 0);
 			if (o)