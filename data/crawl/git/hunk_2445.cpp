 		if (ent->suspect->refcnt <= 0) {
 			fprintf(stderr, "%s in %s has negative refcnt %d\n",
 				ent->suspect->path,
-				sha1_to_hex(ent->suspect->commit->object.sha1),
+				oid_to_hex(&ent->suspect->commit->object.oid),
 				ent->suspect->refcnt);
 			baa = 1;
 		}