 	write_name_quoted(path, stdout, '\n');
 }
 
+/*
+ * Porcelain/Incremental format wants to show a lot of details per
+ * commit.  Instead of repeating this every line, emit it only once,
+ * the first time each commit appears in the output.
+ */
+static int emit_one_suspect_detail(struct origin *suspect)
+{
+	struct commit_info ci;
+
+	if (suspect->commit->object.flags & METAINFO_SHOWN)
+		return 0;
+
+	suspect->commit->object.flags |= METAINFO_SHOWN;
+	get_commit_info(suspect->commit, &ci, 1);
+	printf("author %s\n", ci.author);
+	printf("author-mail %s\n", ci.author_mail);
+	printf("author-time %lu\n", ci.author_time);
+	printf("author-tz %s\n", ci.author_tz);
+	printf("committer %s\n", ci.committer);
+	printf("committer-mail %s\n", ci.committer_mail);
+	printf("committer-time %lu\n", ci.committer_time);
+	printf("committer-tz %s\n", ci.committer_tz);
+	printf("summary %s\n", ci.summary);
+	if (suspect->commit->object.flags & UNINTERESTING)
+		printf("boundary\n");
+	if (suspect->previous) {
+		struct origin *prev = suspect->previous;
+		printf("previous %s ", sha1_to_hex(prev->commit->object.sha1));
+		write_name_quoted(prev->path, stdout, '\n');
+	}
+	return 1;
+}
+
 /*
  * The blame_entry is found to be guilty for the range.  Mark it
  * as such, and show it in incremental output.
