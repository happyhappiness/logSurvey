 	diff_tree_release_paths(&opt);
 }
 
+static int merge_one_change(struct notes_merge_options *o,
+			    struct notes_merge_pair *p, struct notes_tree *t)
+{
+	/*
+	 * Return 0 if change was resolved (and added to notes_tree),
+	 * 1 if conflict
+	 */
+	switch (o->strategy) {
+	case NOTES_MERGE_RESOLVE_MANUAL:
+		return 1;
+	case NOTES_MERGE_RESOLVE_OURS:
+		OUTPUT(o, 2, "Using local notes for %s", sha1_to_hex(p->obj));
+		/* nothing to do */
+		return 0;
+	case NOTES_MERGE_RESOLVE_THEIRS:
+		OUTPUT(o, 2, "Using remote notes for %s", sha1_to_hex(p->obj));
+		if (add_note(t, p->obj, p->remote, combine_notes_overwrite))
+			die("BUG: combine_notes_overwrite failed");
+		return 0;
+	case NOTES_MERGE_RESOLVE_UNION:
+		OUTPUT(o, 2, "Concatenating local and remote notes for %s",
+		       sha1_to_hex(p->obj));
+		if (add_note(t, p->obj, p->remote, combine_notes_concatenate))
+			die("failed to concatenate notes "
+			    "(combine_notes_concatenate)");
+		return 0;
+	}
+	die("Unknown strategy (%i).", o->strategy);
+}
+
 static int merge_changes(struct notes_merge_options *o,
 			 struct notes_merge_pair *changes, int *num_changes,
 			 struct notes_tree *t)
