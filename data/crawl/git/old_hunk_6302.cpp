	return (e < 3 * x) ? n : n - 1;
}

int show_bisect_vars(struct rev_info *revs, int reaches, int all, int show_all)
{
	int cnt;
	char hex[41];

	if (!revs->commits)
		return 1;

	/*
	 * revs->commits can reach "reaches" commits among
	 * "all" commits.  If it is good, then there are
