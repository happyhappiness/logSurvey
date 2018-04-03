static void free_message(struct commit *commit, struct commit_message *msg)
{
	free(msg->parent_label);
	unuse_commit_buffer(commit, msg->message);
}

static void write_cherry_pick_head(struct commit *commit, const char *pseudoref)