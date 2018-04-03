 	if (!usable_delta) {
 		if (entry->type == OBJ_BLOB &&
 		    entry->size > big_file_threshold &&
-		    (st = open_istream(entry->idx.sha1, &type, &size, NULL)) != NULL)
+		    (st = open_istream(entry->idx.oid.hash, &type, &size, NULL)) != NULL)
 			buf = NULL;
 		else {
-			buf = read_sha1_file(entry->idx.sha1, &type, &size);
+			buf = read_sha1_file(entry->idx.oid.hash, &type,
+					     &size);
 			if (!buf)
-				die(_("unable to read %s"), sha1_to_hex(entry->idx.sha1));
+				die(_("unable to read %s"),
+				    oid_to_hex(&entry->idx.oid));
 		}
 		/*
 		 * make sure no cached delta data remains from a
