 		rollback_lock_file(&packlock);
 		return 0;
 	}
+
+	/* Remove any other accumulated cruft: */
+	do_for_each_entry_in_dir(packed, 0, curate_packed_ref_fn, &refs_to_delete);
+	for_each_string_list_item(ref_to_delete, &refs_to_delete) {
+		if (remove_entry(packed, ref_to_delete->string) == -1)
+			die("internal error");
+	}
+
+	/* Write what remains: */
 	write_or_die(fd, PACKED_REFS_HEADER, strlen(PACKED_REFS_HEADER));
-	do_for_each_entry_in_dir(packed, 0, repack_ref_fn, &fd);
+	do_for_each_entry_in_dir(packed, 0, write_packed_entry_fn, &fd);
 	return commit_lock_file(&packlock);
 }
 