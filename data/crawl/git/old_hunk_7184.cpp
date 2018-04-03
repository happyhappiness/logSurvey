	git_config_set(key, tracking.remote ?  tracking.remote : ".");
	sprintf(key, "branch.%s.merge", new_ref);
	git_config_set(key, tracking.src ? tracking.src : orig_ref);
	free(tracking.src);
	printf("Branch %s set up to track %s branch %s.\n", new_ref,
		tracking.remote ? "remote" : "local", orig_ref);

	return 0;
}
