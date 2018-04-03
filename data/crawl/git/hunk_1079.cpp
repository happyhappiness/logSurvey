  * If the work tree has unstaged or uncommitted changes, dies with the
  * appropriate message.
  */
-static void die_on_unclean_work_tree(void)
+static int require_clean_work_tree(const char *action, const char *hint,
+		int gently)
 {
 	struct lock_file *lock_file = xcalloc(1, sizeof(*lock_file));
-	int do_die = 0;
+	int err = 0;
 
 	hold_locked_index(lock_file, 0);
 	refresh_cache(REFRESH_QUIET);
 	update_index_if_able(&the_index, lock_file);
 	rollback_lock_file(lock_file);
 
 	if (has_unstaged_changes()) {
-		error(_("Cannot pull with rebase: You have unstaged changes."));
-		do_die = 1;
+		/* TRANSLATORS: the action is e.g. "pull with rebase" */
+		error(_("Cannot %s: You have unstaged changes."), _(action));
+		err = 1;
 	}
 
 	if (has_uncommitted_changes()) {
-		if (do_die)
+		if (err)
 			error(_("Additionally, your index contains uncommitted changes."));
 		else
-			error(_("Cannot pull with rebase: Your index contains uncommitted changes."));
-		do_die = 1;
+			error(_("Cannot %s: Your index contains uncommitted changes."),
+			      _(action));
+		err = 1;
 	}
 
-	if (do_die)
-		exit(1);
+	if (err) {
+		if (hint)
+			error("%s", hint);
+		if (!gently)
+			exit(128);
+	}
+
+	return err;
 }
 
 /**
