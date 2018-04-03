 	struct object_entry *e;
 
 	if (**p == ':') {	/* <mark> */
-		char *endptr;
-		e = find_mark(strtoumax(*p + 1, &endptr, 10));
-		if (endptr == *p + 1)
-			die("Invalid mark: %s", command_buf.buf);
+		e = find_mark(parse_mark_ref_space(p));
 		if (!e)
 			die("Unknown mark: %s", command_buf.buf);
-		*p = endptr;
 		hashcpy(sha1, e->idx.sha1);
 	} else {	/* <sha1> */
 		if (get_sha1_hex(*p, sha1))
-			die("Invalid SHA1: %s", command_buf.buf);
+			die("Invalid dataref: %s", command_buf.buf);
 		e = find_object(sha1);
 		*p += 40;
 	}
