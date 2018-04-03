 	return st;
 }
 
+static int mark_redundant_parents(struct rev_info *revs, struct commit *commit)
+{
+	struct commit_list *h = reduce_heads(commit->parents);
+	int i = 0, marked = 0;
+	struct commit_list *po, *pn;
+
+	/* Want these for sanity-checking only */
+	int orig_cnt = commit_list_count(commit->parents);
+	int cnt = commit_list_count(h);
+
+	/*
+	 * Not ready to remove items yet, just mark them for now, based
+	 * on the output of reduce_heads(). reduce_heads outputs the reduced
+	 * set in its original order, so this isn't too hard.
+	 */
+	po = commit->parents;
+	pn = h;
+	while (po) {
+		if (pn && po->item == pn->item) {
+			pn = pn->next;
+			i++;
+		} else {
+			po->item->object.flags |= TMP_MARK;
+			marked++;
+		}
+		po=po->next;
+	}
+
+	if (i != cnt || cnt+marked != orig_cnt)
+		die("mark_redundant_parents %d %d %d %d", orig_cnt, cnt, i, marked);
+
+	free_commit_list(h);
+
+	return marked;
+}
+
+static int remove_marked_parents(struct rev_info *revs, struct commit *commit)
+{
+	struct commit_list **pp, *p;
+	int nth_parent, removed = 0;
+
+	pp = &commit->parents;
+	nth_parent = 0;
+	while ((p = *pp) != NULL) {
+		struct commit *parent = p->item;
+		if (parent->object.flags & TMP_MARK) {
+			parent->object.flags &= ~TMP_MARK;
+			*pp = p->next;
+			free(p);
+			removed++;
+			compact_treesame(revs, commit, nth_parent);
+			continue;
+		}
+		pp = &p->next;
+		nth_parent++;
+	}
+
+	/* Removing parents can only increase TREESAMEness */
+	if (removed && !(commit->object.flags & TREESAME))
+		update_treesame(revs, commit);
+
+	return nth_parent;
+}
+
 static struct commit_list **simplify_one(struct rev_info *revs, struct commit *commit, struct commit_list **tail)
 {
 	struct commit_list *p;
