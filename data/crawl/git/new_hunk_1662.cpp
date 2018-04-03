		report(_("Untracked cache enabled for '%s'"), get_git_work_tree());
		break;
	default:
		die("BUG: bad untracked_cache value: %d", untracked_cache);
	}

	if (active_cache_changed) {
