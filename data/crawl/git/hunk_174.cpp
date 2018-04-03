 			die("unable to pack objects reachable from tag %s",
 			    oid_to_hex(oid));
 
-		add_object_entry(tag->object.oid.hash, OBJ_TAG, NULL, 0);
+		add_object_entry(&tag->object.oid, OBJ_TAG, NULL, 0);
 
 		if (tag->tagged->type != OBJ_TAG)
 			return;
