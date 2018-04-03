 
 			if (!tag->tagged)
 				die("bad tag");
-			object = parse_object_or_die(get_object_hash(*tag->tagged), NULL);
+			object = parse_object_or_die(tag->tagged->oid.hash, NULL);
 		}
 
 		if (object->flags & UNINTERESTING)
