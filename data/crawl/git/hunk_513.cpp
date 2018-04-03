 
 			if (!tag->tagged)
 				die("bad tag");
-			object = parse_object_or_die(tag->tagged->oid.hash, NULL);
+			object = parse_object_or_die(&tag->tagged->oid, NULL);
 		}
 
 		if (object->flags & UNINTERESTING)
