 	if (S_ISGITLINK(mode))
 		allow_missing = 1;
 
-	if (!allow_missing)
-		type = sha1_object_info(sha1, NULL);
-	else
-		type = object_type(mode);
-
-	if (type < 0)
-		die("object %s unavailable", sha1_to_hex(sha1));
 
 	*ntr++ = 0; /* now at the beginning of SHA1 */
-	if (type != type_from_string(ptr))
-		die("object type %s mismatch (%s)", ptr, typename(type));
 
 	path = ntr + 41;  /* at the beginning of name */
 	if (line_termination && path[0] == '"') {
