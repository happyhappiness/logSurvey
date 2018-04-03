 			add_pending_object(revs, object, tag->tag);
 		if (!tag->tagged)
 			die("bad tag");
-		object = parse_object(get_object_hash(*tag->tagged));
+		object = parse_object(tag->tagged->oid.hash);
 		if (!object) {
 			if (flags & UNINTERESTING)
 				return NULL;
