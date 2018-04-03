		return error("Not tracking: ambiguous information for ref %s",
				orig_ref);

	install_branch_config(BRANCH_CONFIG_VERBOSE, new_ref, tracking.remote,
			      tracking.src ? tracking.src : orig_ref);

	free(tracking.src);
	return 0;
}

