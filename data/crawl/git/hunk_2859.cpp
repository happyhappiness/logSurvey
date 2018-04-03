 					       LOCK_DIE_ON_ERROR);
 		if (fd < 0)
 			die_errno(_("Could not open '%s' for writing"), filename);
-		read_ref(pseudoref, actual_old_sha1);
+		if (read_ref(pseudoref, actual_old_sha1))
+			die("could not read ref '%s'", pseudoref);
 		if (hashcmp(actual_old_sha1, old_sha1)) {
 			warning("Unexpected sha1 when deleting %s", pseudoref);
 			rollback_lock_file(&lock);