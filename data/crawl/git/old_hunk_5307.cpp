		die("git write-tree failed to write a tree");
}

static int try_merge_strategy(const char *strategy, struct commit_list *common,
			      const char *head_arg)
{
	const char **args;
	int i = 0, x = 0, ret;
	struct commit_list *j;
	struct strbuf buf = STRBUF_INIT;
	int index_fd;
	struct lock_file *lock = xcalloc(1, sizeof(struct lock_file));

