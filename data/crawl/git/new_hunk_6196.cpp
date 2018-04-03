
		revs.commits = find_bisection(revs.commits, &reaches, &all,
					      bisect_find_all);

		if (bisect_show_vars)
			return show_bisect_vars(&info, reaches, all);
	}

	traverse_commit_list(&revs,
			     quiet ? finish_commit : show_commit,
			     quiet ? finish_object : show_object,
			     &info);

	return 0;
}
