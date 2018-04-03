 	free_commit_list(result);
 }
 
-/*
- * This function runs the command "git rev-list $_good ^$_bad"
- * and returns 1 if it produces some output, 0 otherwise.
- */
-static int check_ancestors(void)
+static int check_ancestors(const char *prefix)
 {
-	struct argv_array rev_argv = { NULL, 0, 0 };
-	struct strbuf str = STRBUF_INIT;
-	int i, result = 0;
-	struct child_process rls;
-	FILE *rls_fout;
+	struct rev_info revs;
+	struct object_array pending_copy;
+	int i, res;
 
-	argv_array_push(&rev_argv, xstrdup("rev-list"));
-	argv_array_push_sha1(&rev_argv, current_bad_sha1, "^%s");
-	for (i = 0; i < good_revs.sha1_nr; i++)
-		argv_array_push_sha1(&rev_argv, good_revs.sha1[i], "%s");
-	argv_array_push(&rev_argv, NULL);
+	bisect_rev_setup(&revs, prefix, "^%s", "%s", 0);
 
-	memset(&rls, 0, sizeof(rls));
-	rls.argv = rev_argv.argv;
-	rls.out = -1;
-	rls.git_cmd = 1;
-	if (start_command(&rls))
-		die("Could not launch 'git rev-list' command.");
-	rls_fout = fdopen(rls.out, "r");
-	while (strbuf_getline(&str, rls_fout, '\n') != EOF) {
-		strbuf_trim(&str);
-		if (*str.buf) {
-			result = 1;
-			break;
-		}
+	/* Save pending objects, so they can be cleaned up later. */
+	memset(&pending_copy, 0, sizeof(pending_copy));
+	for (i = 0; i < revs.pending.nr; i++)
+		add_object_array(revs.pending.objects[i].item,
+				 revs.pending.objects[i].name,
+				 &pending_copy);
+
+	bisect_common(&revs);
+	res = (revs.commits != NULL);
+
+	/* Clean up objects used, as they will be reused. */
+	for (i = 0; i < pending_copy.nr; i++) {
+		struct object *o = pending_copy.objects[i].item;
+		unparse_commit((struct commit *)o);
 	}
-	fclose(rls_fout);
-	finish_command(&rls);
 
-	return result;
+	return res;
 }
 
 /*
