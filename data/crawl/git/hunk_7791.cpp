 		strbuf_release(&buf);
 	}
 	maybe_flush_or_die(stdout, "stdout");
+	finish_commit(commit);
+}
+
+static void finish_commit(struct commit *commit)
+{
 	if (commit->parents) {
 		free_commit_list(commit->parents);
 		commit->parents = NULL;
