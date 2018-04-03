	}
}

static int revert_or_cherry_pick(int argc, const char **argv)
{
	unsigned char head[20];
	struct commit *base, *next, *parent;
	const char *base_label, *next_label;
	int i, index_fd, clean;
	struct commit_message msg = { NULL, NULL, NULL, NULL, NULL };

	char *defmsg = git_pathdup("MERGE_MSG");
	struct merge_options o;
	struct tree *result, *next_tree, *base_tree, *head_tree;
	static struct lock_file index_lock;
	struct strbuf msgbuf = STRBUF_INIT;

	git_config(git_default_config, NULL);
