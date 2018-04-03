 	if (!obj) {
 		/* ... these references to parent->fld are safe here */
 		printf("broken link from %7s %s\n",
-			   typename(parent->type), sha1_to_hex(parent->sha1));
+			   typename(parent->type), oid_to_hex(&parent->oid));
 		printf("broken link from %7s %s\n",
 			   (type == OBJ_ANY ? "unknown" : typename(type)), "unknown");
 		errors_found |= ERROR_REACHABLE;
