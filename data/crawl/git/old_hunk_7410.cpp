			continue;

		fprintf(stderr, "Recorded resolution for '%s'.\n", path);
		copy_file(path, rr_path(name, "postimage"));
tail_optimization:
		if (i < rr->nr - 1)
			memmove(rr->items + i,
