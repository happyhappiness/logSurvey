 		return 0;
 	}
 
+	alias = alias_lookup(argv[0]);
+	if (alias && !is_git_command(argv[0])) {
+		printf("`git %s' is aliased to `%s'\n", argv[0], alias);
+		return 0;
+	}
+
 	switch (help_format) {
 	case HELP_FORMAT_MAN:
 		show_man_page(argv[0]);