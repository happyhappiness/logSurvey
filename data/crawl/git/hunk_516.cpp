 	if (!has_object_file(oid))
 		return -1;
 
-	o = parse_object(oid->hash);
+	o = parse_object(oid);
 	if (!o)
 		die("oops (%s)", oid_to_hex(oid));
 	if (o->type == OBJ_COMMIT) {
