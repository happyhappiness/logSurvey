 	if (!(obj->flags & HAS_OBJ)) {
 		if (has_sha1_pack(get_object_hash(*obj)))
 			return; /* it is in pack - forget about it */
-		if (connectivity_only && has_sha1_file(obj->sha1))
+		if (connectivity_only && has_object_file(&obj->oid))
 			return;
-		printf("missing %s %s\n", typename(obj->type), sha1_to_hex(obj->sha1));
+		printf("missing %s %s\n", typename(obj->type), oid_to_hex(&obj->oid));
 		errors_found |= ERROR_REACHABLE;
 		return;
 	}
