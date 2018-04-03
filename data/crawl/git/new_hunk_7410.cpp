			continue;

		fprintf(stderr, "Recorded resolution for '%s'.\n", path);
		copy_file(rr_path(name, "postimage"), path, 0666);
tail_optimization:
		if (i < rr->nr - 1)
			memmove(rr->items + i,
