 	new_refs = 0;
 	for (ref = remote_refs; ref; ref = ref->next) {
 		char old_hex[60], *new_hex;
-		int delete_ref;
+		int will_delete_ref;
 
 		if (!ref->peer_ref)
 			continue;
 
-		delete_ref = is_null_sha1(ref->peer_ref->new_sha1);
-		if (delete_ref && !allow_deleting_refs) {
+
+		will_delete_ref = is_null_sha1(ref->peer_ref->new_sha1);
+		if (will_delete_ref && !allow_deleting_refs) {
 			error("remote does not support deleting refs");
 			ret = -2;
 			continue;
 		}
-		if (!delete_ref &&
+		if (!will_delete_ref &&
 		    !hashcmp(ref->old_sha1, ref->peer_ref->new_sha1)) {
 			if (verbose)
 				fprintf(stderr, "'%s': up-to-date\n", ref->name);
