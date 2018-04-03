		hit = grep_cache(&opt, paths, cached);
	} else {
		if (cached)
			die(_("both --cached and trees are given."));
		hit = grep_objects(&opt, paths, &list);
	}
