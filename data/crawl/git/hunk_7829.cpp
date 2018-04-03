 	}
 }
 
+/*
+ * This gives a rough estimate for how many commits we
+ * will print out in the list.
+ */
+static int estimate_commit_count(struct rev_info *rev, struct commit_list *list)
+{
+	int n = 0;
+
+	while (list) {
+		struct commit *commit = list->item;
+		unsigned int flags = commit->object.flags;
+
+		list = list->next;
+		if (flags & UNINTERESTING)
+			continue;
+		if (rev->prune_fn && rev->dense && !(flags & TREECHANGE)) {
+			if (commit->parents && !commit->parents->next)
+				continue;
+		}
+		n++;
+	}
+	return n;
+}
+
+static void show_early_header(struct rev_info *rev, const char *stage, int nr)
+{
+	if (rev->shown_one) {
+		rev->shown_one = 0;
+		if (rev->commit_format != CMIT_FMT_ONELINE)
+			putchar(rev->diffopt.line_termination);
+	}
+	printf("Final output: %d %s\n", nr, stage);
+}
+
+struct itimerval early_output_timer;
+
 static void log_show_early(struct rev_info *revs, struct commit_list *list)
 {
 	int i = revs->early_output;
+	int show_header = 1;
 
 	sort_in_topological_order(&list, revs->lifo);
 	while (list && i) {
 		struct commit *commit = list->item;
-		log_tree_commit(revs, commit);
+		switch (simplify_commit(revs, commit)) {
+		case commit_show:
+			if (show_header) {
+				int n = estimate_commit_count(revs, list);
+				show_early_header(revs, "incomplete", n);
+				show_header = 0;
+			}
+			log_tree_commit(revs, commit);
+			i--;
+			break;
+		case commit_ignore:
+			break;
+		case commit_error:
+			return;
+		}
 		list = list->next;
-		i--;
 	}
+
+	/* Did we already get enough commits for the early output? */
+	if (!i)
+		return;
+
+	/*
+	 * ..if no, then repeat it twice a second until we
+	 * do.
+	 *
+	 * NOTE! We don't use "it_interval", because if the
+	 * reader isn't listening, we want our output to be
+	 * throttled by the writing, and not have the timer
+	 * trigger every second even if we're blocked on a
+	 * reader!
+	 */
+	early_output_timer.it_value.tv_sec = 0;
+	early_output_timer.it_value.tv_usec = 500000;
+	setitimer(ITIMER_REAL, &early_output_timer, NULL);
 }
 
 static void early_output(int signal)
