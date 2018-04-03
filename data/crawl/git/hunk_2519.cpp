 		if (!object) {
 			if (flags & UNINTERESTING)
 				return NULL;
-			die("bad object %s", sha1_to_hex(tag->tagged->sha1));
+			die("bad object %s", oid_to_hex(&tag->tagged->oid));
 		}
 		object->flags |= flags;
 		/*
