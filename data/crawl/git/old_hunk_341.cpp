		if (!cached)
			setup_work_tree();

		hit = grep_cache(&opt, &pathspec, cached);
	} else {
		if (cached)
			die(_("both --cached and trees are given."));
		hit = grep_objects(&opt, &pathspec, &list);
	}

	if (num_threads)
