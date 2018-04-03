 		die("Could not parse commit from NOTES_MERGE_PARTIAL.");
 
 	if (partial->parents)
-		hashcpy(parent_sha1, partial->parents->item->object.sha1);
+		hashcpy(parent_sha1, get_object_hash(partial->parents->item->object));
 	else
 		hashclr(parent_sha1);
 
