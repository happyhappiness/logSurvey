
	memset(&tracking, 0, sizeof(tracking));
	tracking.spec.dst = (char *)orig_ref;
	if (for_each_remote(find_tracked_branch, &tracking) ||
			!tracking.matches)
		return 1;

	if (tracking.matches > 1)
		return error("Not tracking: ambiguous information for ref %s",
				orig_ref);

	if (tracking.matches == 1) {
		sprintf(key, "branch.%s.remote", new_ref);
		git_config_set(key, tracking.remote ?  tracking.remote : ".");
		sprintf(key, "branch.%s.merge", new_ref);
		git_config_set(key, tracking.src);
		free(tracking.src);
		printf("Branch %s set up to track remote branch %s.\n",
			       new_ref, orig_ref);
	}

	return 0;
}

void create_branch(const char *head,
		   const char *name, const char *start_name,
		   int force, int reflog, int track)
{
	struct ref_lock *lock;
	struct commit *commit;
