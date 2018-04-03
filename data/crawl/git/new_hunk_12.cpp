		die(_("unable to write new index file"));

	if (!opts->force && !opts->quiet)
		show_local_changes(&new_branch_info->commit->object, &opts->diff_options);

	return 0;
}

static void report_tracking(struct branch_info *new_branch_info)
{
	struct strbuf sb = STRBUF_INIT;
	struct branch *branch = branch_get(new_branch_info->name);

	if (!format_tracking_info(branch, &sb))
		return;
