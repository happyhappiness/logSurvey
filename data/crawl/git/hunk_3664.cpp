 			/* only commits */
 			continue;
 
-		object = parse_object(sha1);
+		commit = lookup_commit(sha1);
+		if (!commit)
+			die("not a commit? can't happen: %s", sha1_to_hex(sha1));
+
+		object = &commit->object;
 
 		if (object->flags & SHOWN)
 			error("Object %s already has a mark", sha1_to_hex(sha1));