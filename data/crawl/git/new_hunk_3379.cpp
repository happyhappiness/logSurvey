	}
}

static int count_parents(struct commit *commit)
{
	struct commit_list *parents = commit->parents;
