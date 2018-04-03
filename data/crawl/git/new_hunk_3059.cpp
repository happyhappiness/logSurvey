		die(_("Cannot update paths and switch to branch '%s' at the same time."),
		    opts->new_branch);

	if (opts->patch_mode)
		return run_add_interactive(revision, "--patch=checkout",
					   &opts->pathspec);
