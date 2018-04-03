	}
}

static int cmd_log_walk(struct rev_info *rev)
{
	struct commit *commit;

	prepare_revision_walk(rev);
	while ((commit = get_revision(rev)) != NULL) {
		log_tree_commit(rev, commit);
		if (!rev->reflog_info) {
