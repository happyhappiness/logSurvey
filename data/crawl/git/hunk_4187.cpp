 			branch_name = argv[0];
 		else
 			usage_with_options(builtin_branch_usage, options);
+
+		strbuf_addf(&branch_ref, "refs/heads/%s", branch_name);
+		if (!ref_exists(branch_ref.buf)) {
+			strbuf_release(&branch_ref);
+
+			if (!argc)
+				return error("No commit on branch '%s' yet.",
+					     branch_name);
+			else
+				return error("No such branch '%s'.", branch_name);
+		}
+		strbuf_release(&branch_ref);
+
 		if (edit_branch_description(branch_name))
 			return 1;
 	} else if (rename) {
