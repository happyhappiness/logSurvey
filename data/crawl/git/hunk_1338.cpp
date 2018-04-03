 		strbuf_release(&idx_file);
 	}
 
-	if (shallow_file) {
-		argv[ac++] = "--shallow-file";
-		argv[ac++] = shallow_file;
+	if (opt->shallow_file) {
+		argv_array_push(&rev_list.args, "--shallow-file");
+		argv_array_push(&rev_list.args, opt->shallow_file);
 	}
-	argv[ac++] = "rev-list";
-	argv[ac++] = "--objects";
-	argv[ac++] = "--stdin";
-	argv[ac++] = "--not";
-	argv[ac++] = "--all";
-	if (quiet)
-		argv[ac++] = "--quiet";
-	argv[ac] = NULL;
+	argv_array_push(&rev_list.args,"rev-list");
+	argv_array_push(&rev_list.args, "--objects");
+	argv_array_push(&rev_list.args, "--stdin");
+	argv_array_push(&rev_list.args, "--not");
+	argv_array_push(&rev_list.args, "--all");
+	argv_array_push(&rev_list.args, "--quiet");
+	if (opt->progress)
+		argv_array_pushf(&rev_list.args, "--progress=%s",
+				 _("Checking connectivity"));
 
-	rev_list.argv = argv;
 	rev_list.git_cmd = 1;
 	rev_list.in = -1;
 	rev_list.no_stdout = 1;
-	rev_list.no_stderr = quiet;
+	if (opt->err_fd)
+		rev_list.err = opt->err_fd;
+	else
+		rev_list.no_stderr = opt->quiet;
+
 	if (start_command(&rev_list))
 		return error(_("Could not run 'git rev-list'"));
 
