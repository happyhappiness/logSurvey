 		return 0;
 	}
 	if (!intent_only) {
-		if (index_path(ce->sha1, path, st, HASH_WRITE_OBJECT)) {
+		if (index_path(ce->oid.hash, path, st, HASH_WRITE_OBJECT)) {
 			free(ce);
 			return error("unable to index file %s", path);
 		}
