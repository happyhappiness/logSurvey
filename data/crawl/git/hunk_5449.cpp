 	s = lookup_branch(from);
 	if (s) {
 		hashcpy(sha1, s->sha1);
+		type = OBJ_COMMIT;
 	} else if (*from == ':') {
 		struct object_entry *oe;
 		from_mark = strtoumax(from + 1, NULL, 10);
 		oe = find_mark(from_mark);
-		if (oe->type != OBJ_COMMIT)
-			die("Mark :%" PRIuMAX " not a commit", from_mark);
+		type = oe->type;
 		hashcpy(sha1, oe->sha1);
 	} else if (!get_sha1(from, sha1)) {
 		unsigned long size;
 		char *buf;
 
-		buf = read_object_with_reference(sha1,
-			commit_type, &size, sha1);
+		buf = read_sha1_file(sha1, &type, &size);
 		if (!buf || size < 46)
 			die("Not a valid commit: %s", from);
 		free(buf);
