	if (is_directory(mkpath("%s/.git/objects", ref_git)))
		ref_git = mkpath("%s/.git", ref_git);
	else if (!is_directory(mkpath("%s/objects", ref_git)))
		die(_("reference repository '%s' is not a local directory."),
		    option_reference);

	ref_git_copy = xstrdup(ref_git);
