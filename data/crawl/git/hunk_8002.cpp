 		wt_status_print_verbose(s);
 	if (!s->commitable) {
 		if (s->amend)
-			printf("# No changes\n");
+			fprintf(s->fp, "# No changes\n");
 		else if (s->workdir_dirty)
 			printf("no changes added to commit (use \"git add\" and/or \"git commit -a\")\n");
 		else if (s->workdir_untracked)
