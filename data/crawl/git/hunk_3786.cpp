 	DIFF_QUEUE_CLEAR(src);
 }
 
-static void queue_diffs(struct diff_options *opt,
+static void filter_diffs_for_paths(struct line_log_data *range, int keep_deletions)
+{
+	int i;
+	struct diff_queue_struct outq;
+	DIFF_QUEUE_CLEAR(&outq);
+
+	for (i = 0; i < diff_queued_diff.nr; i++) {
+		struct diff_filepair *p = diff_queued_diff.queue[i];
+		struct line_log_data *rg = NULL;
+
+		if (!DIFF_FILE_VALID(p->two)) {
+			if (keep_deletions)
+				diff_q(&outq, p);
+			else
+				diff_free_filepair(p);
+			continue;
+		}
+		for (rg = range; rg; rg = rg->next) {
+			if (!strcmp(rg->spec->path, p->two->path))
+				break;
+		}
+		if (rg)
+			diff_q(&outq, p);
+		else
+			diff_free_filepair(p);
+	}
+	free(diff_queued_diff.queue);
+	diff_queued_diff = outq;
+}
+
+static inline int diff_might_be_rename(void)
+{
+	int i;
+	for (i = 0; i < diff_queued_diff.nr; i++)
+		if (!DIFF_FILE_VALID(diff_queued_diff.queue[i]->one)) {
+			/* fprintf(stderr, "diff_might_be_rename found creation of: %s\n", */
+			/* 	diff_queued_diff.queue[i]->two->path); */
+			return 1;
+		}
+	return 0;
+}
+
+static void queue_diffs(struct line_log_data *range,
+			struct diff_options *opt,
 			struct diff_queue_struct *queue,
 			struct commit *commit, struct commit *parent)
 {
