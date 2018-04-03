 			die ("Could not read blob %s", sha1_to_hex(sha1));
 
 		if (object->flags & SHOWN)
-			error("Object %s already has a mark", sha1);
+			error("Object %s already has a mark", sha1_to_hex(sha1));
 
 		mark_object(object, mark);
 		if (last_idnum < mark)