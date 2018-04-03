 	if (!contents && type != OBJ_BLOB)
 		die("BUG: read_loose_object streamed a non-blob");
 
-	obj = parse_object_buffer(oid->hash, type, size, contents, &eaten);
+	obj = parse_object_buffer(oid, type, size, contents, &eaten);
 
 	if (!eaten)
 		free(contents);
