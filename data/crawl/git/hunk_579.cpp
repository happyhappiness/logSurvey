 			if (oe->type != OBJ_COMMIT)
 				die("Mark :%" PRIuMAX " not a commit", idnum);
 			hashcpy(n->oid.hash, oe->idx.sha1);
-		} else if (!get_sha1(from, n->oid.hash)) {
+		} else if (!get_oid(from, &n->oid)) {
 			unsigned long size;
 			char *buf = read_object_with_reference(n->oid.hash,
-							       commit_type,
-							       &size,
-							       n->oid.hash);
+				commit_type, &size, n->oid.hash);
 			if (!buf || size < 46)
 				die("Not a valid commit: %s", from);
 			free(buf);
