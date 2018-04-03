 	wt_status_print_changed(s);
 	if (wt_status_submodule_summary)
 		wt_status_print_submodule_summary(s);
-	wt_status_print_untracked(s);
+	if (show_untracked_files)
+		wt_status_print_untracked(s);
+	else if (s->commitable)
+		 fprintf(s->fp, "# Untracked files not listed (use -u option to show untracked files)\n");
 
 	if (s->verbose && !s->is_initial)
 		wt_status_print_verbose(s);
