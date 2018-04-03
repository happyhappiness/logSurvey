	return 0;
}

static struct lock_file index_lock;

static int update_paths(struct path_list *update)
{
	int i;
	int fd = hold_locked_index(&index_lock, 0);
	int status = 0;

	if (fd < 0)
		return -1;

	for (i = 0; i < update->nr; i++) {
		struct path_list_item *item = &update->items[i];
		if (add_file_to_cache(item->path, ADD_CACHE_IGNORE_ERRORS))
			status = -1;
	}

	if (!status && active_cache_changed) {
		if (write_cache(fd, active_cache, active_nr) ||
		    commit_locked_index(&index_lock))
			die("Unable to write new index file");
	} else if (fd >= 0)
		rollback_lock_file(&index_lock);
	return status;
}

static int do_plain_rerere(struct path_list *rr, int fd)
{
	struct path_list conflict = { NULL, 0, 0, 1 };
	struct path_list update = { NULL, 0, 0, 1 };
	int i;

	find_conflict(&conflict);

	/*
	 * MERGE_RR records paths with conflicts immediately after merge
	 * failed.  Some of the conflicted paths might have been hand resolved
	 * in the working tree since then, but the initial run would catch all
	 * and register their preimages.
	 */

	for (i = 0; i < conflict.nr; i++) {
		const char *path = conflict.items[i].path;
		if (!path_list_has_path(rr, path)) {
			unsigned char sha1[20];
			char *hex;
			int ret;
			ret = handle_file(path, sha1, NULL);
			if (ret < 1)
				continue;
			hex = xstrdup(sha1_to_hex(sha1));
			path_list_insert(path, rr)->util = hex;
			if (mkdir(git_path("rr-cache/%s", hex), 0755))
				continue;;
			handle_file(path, NULL, rr_path(hex, "preimage"));
			fprintf(stderr, "Recorded preimage for '%s'\n", path);
		}
	}

	/*
	 * Now some of the paths that had conflicts earlier might have been
	 * hand resolved.  Others may be similar to a conflict already that
	 * was resolved before.
	 */

	for (i = 0; i < rr->nr; i++) {
		int ret;
		const char *path = rr->items[i].path;
		const char *name = (const char *)rr->items[i].util;

		if (has_resolution(name)) {
			if (!merge(name, path)) {
				fprintf(stderr, "Resolved '%s' using "
						"previous resolution.\n", path);
				if (rerere_autoupdate)
					path_list_insert(path, &update);
				goto mark_resolved;
			}
		}

		/* Let's see if we have resolved it. */
		ret = handle_file(path, NULL, NULL);
		if (ret)
			continue;

		fprintf(stderr, "Recorded resolution for '%s'.\n", path);
		copy_file(rr_path(name, "postimage"), path, 0666);
	mark_resolved:
		rr->items[i].util = NULL;
	}

	if (update.nr)
		update_paths(&update);

	return write_rr(rr, fd);
}

static int git_rerere_config(const char *var, const char *value, void *cb)
{
	if (!strcmp(var, "gc.rerereresolved"))
		cutoff_resolve = git_config_int(var, value);
	else if (!strcmp(var, "gc.rerereunresolved"))
		cutoff_noresolve = git_config_int(var, value);
	else if (!strcmp(var, "rerere.enabled"))
		rerere_enabled = git_config_bool(var, value);
	else if (!strcmp(var, "rerere.autoupdate"))
		rerere_autoupdate = git_config_bool(var, value);
	else
		return git_default_config(var, value, cb);
	return 0;
}

static int is_rerere_enabled(void)
{
	struct stat st;
	const char *rr_cache;
	int rr_cache_exists;

	if (!rerere_enabled)
		return 0;

	rr_cache = git_path("rr-cache");
	rr_cache_exists = !stat(rr_cache, &st) && S_ISDIR(st.st_mode);
	if (rerere_enabled < 0)
		return rr_cache_exists;

	if (!rr_cache_exists &&
	    (mkdir(rr_cache, 0777) || adjust_shared_perm(rr_cache)))
		die("Could not create directory %s", rr_cache);
	return 1;
}

static int setup_rerere(struct path_list *merge_rr)
{
	int fd;

	git_config(git_rerere_config, NULL);
	if (!is_rerere_enabled())
		return -1;

	merge_rr_path = xstrdup(git_path("rr-cache/MERGE_RR"));
	fd = hold_lock_file_for_update(&write_lock, merge_rr_path, 1);
	read_rr(merge_rr);
	return fd;
}

int rerere(void)
{
	struct path_list merge_rr = { NULL, 0, 0, 1 };
	int fd;

	fd = setup_rerere(&merge_rr);
	if (fd < 0)
		return 0;
	return do_plain_rerere(&merge_rr, fd);
}

int cmd_rerere(int argc, const char **argv, const char *prefix)
{
	struct path_list merge_rr = { NULL, 0, 0, 1 };
	int i, fd;

	fd = setup_rerere(&merge_rr);
	if (fd < 0)
		return 0;

	if (argc < 2)
		return do_plain_rerere(&merge_rr, fd);
	else if (!strcmp(argv[1], "clear")) {
		for (i = 0; i < merge_rr.nr; i++) {
			const char *name = (const char *)merge_rr.items[i].util;
			if (!has_resolution(name))
				unlink_rr_item(name);
		}
		unlink(merge_rr_path);
	} else if (!strcmp(argv[1], "gc"))
		garbage_collect(&merge_rr);
	else if (!strcmp(argv[1], "status"))
