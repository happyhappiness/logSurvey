			fprintf(stderr,
				"Resolved '%s' using previous resolution.\n",
				path);
	} else if (!handle_file(path, NULL, NULL)) {
		/* The user has resolved it. */
		copy_file(rerere_path(name, "postimage"), path, 0666);
		fprintf(stderr, "Recorded resolution for '%s'.\n", path);
	} else {
		return;
	}
	free(rr_item->util);
	rr_item->util = NULL;
}