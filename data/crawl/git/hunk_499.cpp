 	 * verify_packfile(), data_valid variable for details.
 	 */
 	struct object *obj;
-	obj = parse_object_buffer(oid->hash, type, size, buffer, eaten);
+	obj = parse_object_buffer(oid, type, size, buffer, eaten);
 	if (!obj) {
 		errors_found |= ERROR_OBJECT;
 		return error("%s: object corrupt or missing", oid_to_hex(oid));
