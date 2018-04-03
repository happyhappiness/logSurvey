 		hook_arg2 = use_message;
 	} else if (!stat(git_path("MERGE_MSG"), &statbuf)) {
 		if (strbuf_read_file(&sb, git_path("MERGE_MSG"), 0) < 0)
-			die("could not read MERGE_MSG: %s", strerror(errno));
+			die_errno("could not read MERGE_MSG");
 		hook_arg1 = "merge";
 	} else if (!stat(git_path("SQUASH_MSG"), &statbuf)) {
 		if (strbuf_read_file(&sb, git_path("SQUASH_MSG"), 0) < 0)
-			die("could not read SQUASH_MSG: %s", strerror(errno));
+			die_errno("could not read SQUASH_MSG");
 		hook_arg1 = "squash";
 	} else if (template_file && !stat(template_file, &statbuf)) {
 		if (strbuf_read_file(&sb, template_file, 0) < 0)
-			die("could not read %s: %s",
-			    template_file, strerror(errno));
+			die_errno("could not read '%s'", template_file);
 		hook_arg1 = "template";
 	}
 
