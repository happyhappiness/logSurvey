 	/* <commit-ish> */
 	s = lookup_branch(p);
 	if (s) {
-		if (is_null_sha1(s->sha1))
+		if (is_null_oid(&s->oid))
 			die("Can't add a note on empty branch.");
-		hashcpy(commit_sha1, s->sha1);
+		hashcpy(commit_sha1, s->oid.hash);
 	} else if (*p == ':') {
 		uintmax_t commit_mark = parse_mark_ref_eol(p);
 		struct object_entry *commit_oe = find_mark(commit_mark);
