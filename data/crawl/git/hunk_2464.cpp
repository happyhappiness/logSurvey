 	if (!obj->used) {
 		if (show_dangling)
 			printf("dangling %s %s\n", typename(obj->type),
-			       sha1_to_hex(obj->sha1));
+			       oid_to_hex(&obj->oid));
 		if (write_lost_and_found) {
 			char *filename = git_pathdup("lost-found/%s/%s",
 				obj->type == OBJ_COMMIT ? "commit" : "other",
-				sha1_to_hex(obj->sha1));
+				oid_to_hex(&obj->oid));
 			FILE *f;
 
 			if (safe_create_leading_directories_const(filename)) {
