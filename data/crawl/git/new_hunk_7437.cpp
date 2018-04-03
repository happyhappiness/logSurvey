
	memset(&tracking, 0, sizeof(tracking));
	tracking.spec.dst = (char *)orig_ref;
	if (for_each_remote(find_tracked_branch, &tracking))
		return 1;

	if (!tracking.matches)
		switch (track) {
		case BRANCH_TRACK_ALWAYS:
		case BRANCH_TRACK_EXPLICIT:
			break;
		default:
			return 1;
		}

	if (tracking.matches > 1)
		return error("Not tracking: ambiguous information for ref %s",
				orig_ref);

	sprintf(key, "branch.%s.remote", new_ref);
	git_config_set(key, tracking.remote ?  tracking.remote : ".");
	sprintf(key, "branch.%s.merge", new_ref);
	git_config_set(key, tracking.src ? tracking.src : orig_ref);
	free(tracking.src);
	printf("Branch %s set up to track %s branch %s.\n", new_ref,
		tracking.remote ? "remote" : "local", orig_ref);

	return 0;
}

void create_branch(const char *head,
		   const char *name, const char *start_name,
		   int force, int reflog, enum branch_track track)
{
	struct ref_lock *lock;
	struct commit *commit;
