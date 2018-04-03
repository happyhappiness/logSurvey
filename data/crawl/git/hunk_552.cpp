 
 	for (i = 0; i < pdata->nr_objects; i++) {
 		int found;
-		uint32_t ix = locate_object_entry_hash(pdata, entry->idx.sha1, &found);
+		uint32_t ix = locate_object_entry_hash(pdata,
+						       entry->idx.oid.hash,
+						       &found);
 
 		if (found)
 			die("BUG: Duplicate object in hash");
