 
 			if (!tag->tagged)
 				die("bad tag");
-			object = parse_object_or_die(tag->tagged->sha1, NULL);
+			object = parse_object_or_die(get_object_hash(*tag->tagged), NULL);
 		}
 
 		if (object->flags & UNINTERESTING)
