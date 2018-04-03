	free_ref_list(&ref_list);
}

struct tracking {
	struct refspec spec;
	char *src;
	const char *remote;
	int matches;
};

static int find_tracked_branch(struct remote *remote, void *priv)
{
	struct tracking *tracking = priv;

	if (!remote_find_tracking(remote, &tracking->spec)) {
		if (++tracking->matches == 1) {
			tracking->src = tracking->spec.src;
			tracking->remote = remote->name;
		} else {
			free(tracking->spec.src);
			if (tracking->src) {
				free(tracking->src);
				tracking->src = NULL;
			}
		}
		tracking->spec.src = NULL;
	}

	return 0;
}


/*
 * This is called when new_ref is branched off of orig_ref, and tries
 * to infer the settings for branch.<new_ref>.{remote,merge} from the
 * config.
 */
static int setup_tracking(const char *new_ref, const char *orig_ref)
{
	char key[1024];
	struct tracking tracking;

	if (strlen(new_ref) > 1024 - 7 - 7 - 1)
		return error("Tracking not set up: name too long: %s",
				new_ref);

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

static void create_branch(const char *name, const char *start_name,
