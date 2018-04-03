	return refname_match(branch->merge[i]->src, refname);
}

const char *branch_get_upstream(struct branch *branch)
{
	if (!branch || !branch->merge || !branch->merge[0])
		return NULL;
	return branch->merge[0]->dst;
}

