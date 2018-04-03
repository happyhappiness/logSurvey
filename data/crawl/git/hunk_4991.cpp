 		strbuf_add(&sb, buffer + 2, strlen(buffer + 2));
 		hook_arg1 = "commit";
 		hook_arg2 = use_message;
+	} else if (fixup_message) {
+		struct pretty_print_context ctx = {0};
+		struct commit *commit;
+		commit = lookup_commit_reference_by_name(fixup_message);
+		if (!commit)
+			die("could not lookup commit %s", fixup_message);
+		ctx.output_encoding = get_commit_output_encoding();
+		format_commit_message(commit, "fixup! %s\n\n",
+				      &sb, &ctx);
+		hook_arg1 = "message";
 	} else if (!stat(git_path("MERGE_MSG"), &statbuf)) {
 		if (strbuf_read_file(&sb, git_path("MERGE_MSG"), 0) < 0)
 			die_errno("could not read MERGE_MSG");
