 	for (rm = ref_map; rm; rm = rm->next) {
 		if (rm->peer_ref)
 			read_ref(rm->peer_ref->name, rm->peer_ref->old_sha1);
-
-		printf("%s : %s\n", rm->name, rm->peer_ref ? rm->peer_ref->name : NULL);
-		printf("  < %s\n", sha1_to_hex(rm->old_sha1));
-		if (rm->peer_ref)
-			printf("  > %s\n", sha1_to_hex(rm->peer_ref->old_sha1));
-		if (!rm->peer_ref ||
-		    hashcmp(rm->old_sha1, rm->peer_ref->old_sha1)) {
-			printf("%s needs update.\n", rm->name);
-		}
 	}
 
 	if (fetch_refs(transport, ref_map)) {