 	 * do a full fsck
 	 */
 	if (!obj->parsed) {
-		if (has_sha1_pack(obj->sha1, NULL))
+		if (has_sha1_pack(obj->sha1))
 			return; /* it is in pack - forget about it */
 		printf("missing %s %s\n", typename(obj->type), sha1_to_hex(obj->sha1));
 		errors_found |= ERROR_REACHABLE;
