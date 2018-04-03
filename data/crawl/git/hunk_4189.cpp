 	file->print_name = pname;
 }
 
+int print_stat_summary(FILE *fp, int files, int insertions, int deletions)
+{
+	struct strbuf sb = STRBUF_INIT;
+	int ret;
+
+	if (!files) {
+		assert(insertions == 0 && deletions == 0);
+		return fputs(_(" 0 files changed\n"), fp);
+	}
+
+	strbuf_addf(&sb,
+		    Q_(" %d file changed", " %d files changed", files),
+		    files);
+
+	/*
+	 * For binary diff, the caller may want to print "x files
+	 * changed" with insertions == 0 && deletions == 0.
+	 *
+	 * Not omitting "0 insertions(+), 0 deletions(-)" in this case
+	 * is probably less confusing (i.e skip over "2 files changed
+	 * but nothing about added/removed lines? Is this a bug in Git?").
+	 */
+	if (insertions || deletions == 0) {
+		/*
+		 * TRANSLATORS: "+" in (+) is a line addition marker;
+		 * do not translate it.
+		 */
+		strbuf_addf(&sb,
+			    Q_(", %d insertion(+)", ", %d insertions(+)",
+			       insertions),
+			    insertions);
+	}
+
+	if (deletions || insertions == 0) {
+		/*
+		 * TRANSLATORS: "-" in (-) is a line removal marker;
+		 * do not translate it.
+		 */
+		strbuf_addf(&sb,
+			    Q_(", %d deletion(-)", ", %d deletions(-)",
+			       deletions),
+			    deletions);
+	}
+	strbuf_addch(&sb, '\n');
+	ret = fputs(sb.buf, fp);
+	strbuf_release(&sb);
+	return ret;
+}
+
 static void show_stats(struct diffstat_t *data, struct diff_options *options)
 {
 	int i, len, add, del, adds = 0, dels = 0;
