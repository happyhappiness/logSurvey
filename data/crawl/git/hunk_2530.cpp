 		if (!c || !(c->object.flags & SEEN)) {
 			if (data->flags & VERBOSE)
 				printf("Removing %s from .git/shallow\n",
-				       sha1_to_hex(c->object.sha1));
+				       oid_to_hex(&c->object.oid));
 			return 0;
 		}
 	}
