 
 	while (ref) {
 		printf("%s %s\n",
-		       sha1_to_hex(ref->old_sha1), ref->name);
+		       oid_to_hex(&ref->old_oid), ref->name);
 		ref = ref->next;
 	}
 
