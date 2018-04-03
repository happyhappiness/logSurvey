		for (i = 0; i < merge_rr.nr; i++) {
			const char *path = merge_rr.items[i].string;
			const struct rerere_id *id = merge_rr.items[i].util;
			if (diff_two(rerere_path(id, "preimage"), path, path, path))
				die("unable to generate diff for %s", rerere_path(id, NULL));
		}
	} else
		usage_with_options(rerere_usage, options);
