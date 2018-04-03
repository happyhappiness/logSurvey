	struct commit_list *p;
	for (p = commit->parents; p ; p = p->next) {
		struct commit *parent = p->item;
		printf(" %s", diff_unique_abbrev(parent->object.sha1, abbrev));
	}
}

