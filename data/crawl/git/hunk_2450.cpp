 	}
 
 	if (!match_cnt) {
-		const unsigned char *sha1 = cmit->object.sha1;
+		struct object_id *oid = &cmit->object.oid;
 		if (always) {
-			printf("%s", find_unique_abbrev(sha1, abbrev));
+			printf("%s", find_unique_abbrev(oid->hash, abbrev));
 			if (dirty)
 				printf("%s", dirty);
 			printf("\n");
