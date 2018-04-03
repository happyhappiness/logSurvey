			continue;

		fprintf(stderr, "Recorded resolution for '%s'.\n", path);
		copy_file(rerere_path(name, "postimage"), path, 0666);
	mark_resolved:
		rr->items[i].util = NULL;
	}
