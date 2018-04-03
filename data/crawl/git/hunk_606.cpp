 		die("Expected from command, got %s", command_buf.buf);
 	s = lookup_branch(from);
 	if (s) {
-		if (is_null_sha1(s->sha1))
+		if (is_null_oid(&s->oid))
 			die("Can't tag an empty branch.");
-		hashcpy(sha1, s->sha1);
+		hashcpy(sha1, s->oid.hash);
 		type = OBJ_COMMIT;
 	} else if (*from == ':') {
 		struct object_entry *oe;
