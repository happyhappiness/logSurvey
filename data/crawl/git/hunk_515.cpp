 			add_pending_object(revs, object, tag->tag);
 		if (!tag->tagged)
 			die("bad tag");
-		object = parse_object(tag->tagged->oid.hash);
+		object = parse_object(&tag->tagged->oid);
 		if (!object) {
 			if (flags & UNINTERESTING)
 				return NULL;
