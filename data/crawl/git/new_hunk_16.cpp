	} else if (opts->track == BRANCH_TRACK_UNSPECIFIED)
		opts->track = git_branch_track;

	if (new_branch_info->name && !new_branch_info->commit)
		die(_("Cannot switch branch to a non-commit '%s'"),
		    new_branch_info->name);

	if (new_branch_info->path && !opts->force_detach && !opts->new_branch &&
	    !opts->ignore_other_worktrees) {
		int flag;
		char *head_ref = resolve_refdup("HEAD", 0, NULL, &flag);
		if (head_ref &&
		    (!(flag & REF_ISSYMREF) || strcmp(head_ref, new_branch_info->path)))
			die_if_checked_out(new_branch_info->path, 1);
		free(head_ref);
	}

	if (!new_branch_info->commit && opts->new_branch) {
		struct object_id rev;
		int flag;

		if (!read_ref_full("HEAD", 0, &rev, &flag) &&
		    (flag & REF_ISSYMREF) && is_null_oid(&rev))
			return switch_unborn_to_new_branch(opts);
	}
	return switch_branches(opts, new_branch_info);
}

int cmd_checkout(int argc, const char **argv, const char *prefix)
{
	struct checkout_opts opts;
	struct branch_info new_branch_info;
	char *conflict_style = NULL;
	int dwim_new_local_branch = 1;
	struct option options[] = {
