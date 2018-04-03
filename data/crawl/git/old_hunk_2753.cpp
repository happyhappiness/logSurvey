	}

	diff_ranges_init(&diff);
	collect_diff(&file_parent, &file_target, &diff);

	/* NEEDSWORK should apply some heuristics to prevent mismatches */
	free(rg->path);