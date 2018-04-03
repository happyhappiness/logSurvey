			goto mark_resolved;
		}

		/* Let's see if the user has resolved it. */
		ret = handle_file(path, NULL, NULL);
		if (ret)
			continue;

		copy_file(rerere_path(name, "postimage"), path, 0666);
		fprintf(stderr, "Recorded resolution for '%s'.\n", path);
	mark_resolved:
		free(rr->items[i].util);
		rr->items[i].util = NULL;
