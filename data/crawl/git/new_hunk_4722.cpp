		const char *path = p->one->path;
		switch (p->status) {
		default:
			die(_("unexpected diff status %c"), p->status);
		case DIFF_STATUS_UNMERGED:
			/*
			 * ADD_CACHE_IGNORE_REMOVAL is unset if "git
