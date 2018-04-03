 	return retval >= 0 && (tree_difference == REV_TREE_SAME);
 }
 
+struct treesame_state {
+	unsigned int nparents;
+	unsigned char treesame[FLEX_ARRAY];
+};
+
+static struct treesame_state *initialise_treesame(struct rev_info *revs, struct commit *commit)
+{
+	unsigned n = commit_list_count(commit->parents);
+	struct treesame_state *st = xcalloc(1, sizeof(*st) + n);
+	st->nparents = n;
+	add_decoration(&revs->treesame, &commit->object, st);
+	return st;
+}
+
+/*
+ * Must be called immediately after removing the nth_parent from a commit's
+ * parent list, if we are maintaining the per-parent treesame[] decoration.
+ * This does not recalculate the master TREESAME flag - update_treesame()
+ * should be called to update it after a sequence of treesame[] modifications
+ * that may have affected it.
+ */
+static int compact_treesame(struct rev_info *revs, struct commit *commit, unsigned nth_parent)
+{
+	struct treesame_state *st;
+	int old_same;
+
+	if (!commit->parents) {
+		/*
+		 * Have just removed the only parent from a non-merge.
+		 * Different handling, as we lack decoration.
+		 */
+		if (nth_parent != 0)
+			die("compact_treesame %u", nth_parent);
+		old_same = !!(commit->object.flags & TREESAME);
+		if (rev_same_tree_as_empty(revs, commit))
+			commit->object.flags |= TREESAME;
+		else
+			commit->object.flags &= ~TREESAME;
+		return old_same;
+	}
+
+	st = lookup_decoration(&revs->treesame, &commit->object);
+	if (!st || nth_parent >= st->nparents)
+		die("compact_treesame %u", nth_parent);
+
+	old_same = st->treesame[nth_parent];
+	memmove(st->treesame + nth_parent,
+		st->treesame + nth_parent + 1,
+		st->nparents - nth_parent - 1);
+
+	/*
+	 * If we've just become a non-merge commit, update TREESAME
+	 * immediately, and remove the no-longer-needed decoration.
+	 * If still a merge, defer update until update_treesame().
+	 */
+	if (--st->nparents == 1) {
+		if (commit->parents->next)
+			die("compact_treesame parents mismatch");
+		if (st->treesame[0] && revs->dense)
+			commit->object.flags |= TREESAME;
+		else
+			commit->object.flags &= ~TREESAME;
+		free(add_decoration(&revs->treesame, &commit->object, NULL));
+	}
+
+	return old_same;
+}
+
+static unsigned update_treesame(struct rev_info *revs, struct commit *commit)
+{
+	if (commit->parents && commit->parents->next) {
+		unsigned n;
+		struct treesame_state *st;
+
+		st = lookup_decoration(&revs->treesame, &commit->object);
+		if (!st)
+			die("update_treesame %s", sha1_to_hex(commit->object.sha1));
+		commit->object.flags |= TREESAME;
+		for (n = 0; n < st->nparents; n++) {
+			if (!st->treesame[n]) {
+				commit->object.flags &= ~TREESAME;
+				break;
+			}
+		}
+	}
+
+	return commit->object.flags & TREESAME;
+}
+
 static void try_to_simplify_commit(struct rev_info *revs, struct commit *commit)
 {
 	struct commit_list **pp, *parent;
-	int tree_changed = 0, tree_same = 0, nth_parent = 0;
+	struct treesame_state *ts = NULL;
+	int tree_changed = 0, nth_parent;
 
 	/*
 	 * If we don't do pruning, everything is interesting
