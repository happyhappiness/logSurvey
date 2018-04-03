 
 	buffer = read_sha1_file(oid->hash, &type, &size);
 	if (buffer) {
-		if (check_sha1_signature(repl, buffer, size, typename(type)) < 0) {
+		if (check_sha1_signature(repl, buffer, size, type_name(type)) < 0) {
 			free(buffer);
 			error("sha1 mismatch %s", sha1_to_hex(repl));
 			return NULL;
