 			die("Can't add a note on empty branch.");
 		hashcpy(commit_sha1, s->sha1);
 	} else if (*p == ':') {
-		uintmax_t commit_mark = strtoumax(p + 1, NULL, 10);
+		uintmax_t commit_mark = parse_mark_ref_eol(p);
 		struct object_entry *commit_oe = find_mark(commit_mark);
 		if (commit_oe->type != OBJ_COMMIT)
 			die("Mark :%" PRIuMAX " not a commit", commit_mark);
