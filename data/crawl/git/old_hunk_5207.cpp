	if (read_cache() < 0)
		die("git %s: failed to read the index", me);

	return do_pick_commit();
}

int cmd_revert(int argc, const char **argv, const char *prefix)