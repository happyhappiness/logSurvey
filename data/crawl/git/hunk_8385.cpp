 			die("Mark :%" PRIuMAX " not a commit", idnum);
 		hashcpy(b->sha1, oe->sha1);
 		buf = gfi_unpack_entry(oe, &size);
-		if (!buf || size < 46)
-			die("Not a valid commit: %s", from);
-		if (memcmp("tree ", buf, 5)
-			|| get_sha1_hex(buf + 5, b->branch_tree.versions[1].sha1))
-			die("The commit %s is corrupt", sha1_to_hex(b->sha1));
+		cmd_from_commit(b, buf, size);
 		free(buf);
-		hashcpy(b->branch_tree.versions[0].sha1,
-			b->branch_tree.versions[1].sha1);
-	} else if (!get_sha1(from, b->sha1)) {
-		if (is_null_sha1(b->sha1)) {
-			hashclr(b->branch_tree.versions[0].sha1);
-			hashclr(b->branch_tree.versions[1].sha1);
-		} else {
-			unsigned long size;
-			char *buf;
-
-			buf = read_object_with_reference(b->sha1,
-				commit_type, &size, b->sha1);
-			if (!buf || size < 46)
-				die("Not a valid commit: %s", from);
-			if (memcmp("tree ", buf, 5)
-				|| get_sha1_hex(buf + 5, b->branch_tree.versions[1].sha1))
-				die("The commit %s is corrupt", sha1_to_hex(b->sha1));
-			free(buf);
-			hashcpy(b->branch_tree.versions[0].sha1,
-				b->branch_tree.versions[1].sha1);
-		}
-	} else
+	} else if (!get_sha1(from, b->sha1))
+		cmd_from_existing(b);
+	else
 		die("Invalid ref name or SHA1 expression: %s", from);
 
 	read_next_command();