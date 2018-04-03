			fprintf(stderr,
				"Resolved '%s' using previous resolution.\n",
				path);
		goto mark_resolved;
	}

	/* Let's see if the user has resolved it. */
	if (handle_file(path, NULL, NULL))
		return; /* not yet resolved */

	copy_file(rerere_path(name, "postimage"), path, 0666);
	fprintf(stderr, "Recorded resolution for '%s'.\n", path);
mark_resolved:
	free(rr_item->util);
	rr_item->util = NULL;
}