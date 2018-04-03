	if (require_work_tree && !is_inside_work_tree())
		setup_work_tree();

	if (recurse_submodules &&
	    (show_stage || show_deleted || show_others || show_unmerged ||
	     show_killed || show_modified || show_resolve_undo ||
	     show_valid_bit || show_tag || show_eol || with_tree ||
	     (line_terminator == '\0')))
		die("ls-files --recurse-submodules unsupported mode");

	if (recurse_submodules && error_unmatch)
		die("ls-files --recurse-submodules does not support "
		    "--error-unmatch");

	if (recurse_submodules && argc)
		die("ls-files --recurse-submodules does not support pathspec");

	parse_pathspec(&pathspec, 0,
		       PATHSPEC_PREFER_CWD |
		       PATHSPEC_STRIP_SUBMODULE_SLASH_CHEAP,
