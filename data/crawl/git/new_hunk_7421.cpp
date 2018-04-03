		refresh_cache(REFRESH_QUIET);

		if (unmerged_cache()) {
			error("you need to resolve your current index first");
			return 1;
		}

		/* 2-way merge to the new branch */
		topts.update = 1;
		topts.merge = 1;
		topts.gently = opts->merge;
		topts.verbose_update = !opts->quiet;
		topts.fn = twoway_merge;
		topts.dir = xcalloc(1, sizeof(*topts.dir));
		topts.dir->show_ignored = 1;
		topts.dir->exclude_per_dir = ".gitignore";
		tree = parse_tree_indirect(old->commit->object.sha1);
		init_tree_desc(&trees[0], tree->buffer, tree->size);
		tree = parse_tree_indirect(new->commit->object.sha1);
		init_tree_desc(&trees[1], tree->buffer, tree->size);

		if (unpack_trees(2, trees, &topts)) {
			/*
			 * Unpack couldn't do a trivial merge; either
			 * give up or do a real merge, depending on