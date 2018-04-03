 		struct branch *branch = branch_get(argv[0]);
 		struct strbuf buf = STRBUF_INIT;
 
+		if (argc > 1)
+			die(_("too many branches to unset upstream"));
+
+		if (!branch) {
+			if (!argc || !strcmp(argv[0], "HEAD"))
+				die(_("could not unset upstream of HEAD when "
+				      "it does not point to any branch."));
+			die(_("no such branch '%s'"), argv[0]);
+		}
+
 		if (!branch_has_merge_config(branch)) {
 			die(_("Branch '%s' has no upstream information"), branch->name);
 		}
