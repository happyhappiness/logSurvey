		strbuf_setlen(merge_msg, merge_msg->len - 1);
}

static struct commit_list *collect_parents(struct commit *head_commit,
					   int *head_subsumed,
					   int argc, const char **argv,
