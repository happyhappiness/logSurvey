 	if (s->show_untracked_files)
 		wt_status_print_untracked(s);
 	else if (s->commitable)
-		 fprintf(s->fp, "# Untracked files not listed (use -u option to show untracked files)\n");
+		fprintf(s->fp, "# Untracked files not listed%s\n",
+			advice_status_hints
+			? " (use -u option to show untracked files)" : "");
 
 	if (s->verbose)
 		wt_status_print_verbose(s);
