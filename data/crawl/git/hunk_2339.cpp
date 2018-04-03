 	t->first_non_note = NULL;
 	t->prev_non_note = NULL;
 	t->ref = xstrdup_or_null(notes_ref);
+	t->update_ref = (flags & NOTES_INIT_WRITABLE) ? t->ref : NULL;
 	t->combine_notes = combine_notes;
 	t->initialized = 1;
 	t->dirty = 0;
 
 	if (flags & NOTES_INIT_EMPTY || !notes_ref ||
-	    read_ref(notes_ref, object_sha1))
+	    get_sha1_treeish(notes_ref, object_sha1))
 		return;
+	if (flags & NOTES_INIT_WRITABLE && read_ref(notes_ref, object_sha1))
+		die("Cannot use notes ref %s", notes_ref);
 	if (get_tree_entry(object_sha1, "", sha1, &mode))
 		die("Failed to read notes tree referenced by %s (%s)",
 		    notes_ref, sha1_to_hex(object_sha1));
