	}

	if (!!also + !!only + !!all + !!interactive > 1)
		die("Only one of --include/--only/--all/--interactive can be used.");
	if (argc == 0 && (also || (only && !amend)))
		die("No paths with --include/--only does not make sense.");
	if (argc == 0 && only && amend)
		only_include_assumed = "Clever... amending the last one with dirty index.";
	if (argc > 0 && !also && !only)
		only_include_assumed = "Explicit paths specified without -i nor -o; assuming --only paths...";
	if (!cleanup_arg || !strcmp(cleanup_arg, "default"))
		cleanup_mode = use_editor ? CLEANUP_ALL : CLEANUP_SPACE;
	else if (!strcmp(cleanup_arg, "verbatim"))