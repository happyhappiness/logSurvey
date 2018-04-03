
		revs.commits = find_bisection(revs.commits, &reaches, &all,
					      bisect_find_all);
		if (bisect_show_vars)
			return show_bisect_vars(reaches, all, bisect_find_all);
	}

	traverse_commit_list(&revs,