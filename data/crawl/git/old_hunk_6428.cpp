	return 0;
}

static int should_setup_rebase(const struct tracking *tracking)
{
	switch (autorebase) {
	case AUTOREBASE_NEVER:
		return 0;
	case AUTOREBASE_LOCAL:
		return tracking->remote == NULL;
	case AUTOREBASE_REMOTE:
		return tracking->remote != NULL;
	case AUTOREBASE_ALWAYS:
		return 1;
	}
	return 0;
}

/*
 * This is called when new_ref is branched off of orig_ref, and tries
 * to infer the settings for branch.<new_ref>.{remote,merge} from the
