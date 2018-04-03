}

static int checkout_branch(struct checkout_opts *opts,
			   struct branch_info *new)
{
	if (opts->pathspec.nr)
		die(_("paths cannot be used with switching branches"));
