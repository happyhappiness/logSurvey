 	 */
 	if (repo->can_update_info_refs && !has_object_file(&ref->old_oid)) {
 		obj = lookup_unknown_object(ref->old_oid.hash);
-		if (obj) {
-			fprintf(stderr,	"  fetch %s for %s\n",
-				oid_to_hex(&ref->old_oid), refname);
-			add_fetch_request(obj);
-		}
+		fprintf(stderr,	"  fetch %s for %s\n",
+			oid_to_hex(&ref->old_oid), refname);
+		add_fetch_request(obj);
 	}
 
 	ref->next = remote_refs;