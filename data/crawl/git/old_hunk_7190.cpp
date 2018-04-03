	return new;
}

int add_file_to_index(struct index_state *istate, const char *path, int verbose)
{
	int size, namelen;
	struct stat st;
	struct cache_entry *ce, *alias;
	unsigned ce_option = CE_MATCH_IGNORE_VALID|CE_MATCH_RACY_IS_DIRTY;

	if (lstat(path, &st))
		die("%s: unable to stat (%s)", path, strerror(errno));

	if (!S_ISREG(st.st_mode) && !S_ISLNK(st.st_mode) && !S_ISDIR(st.st_mode))
		die("%s: can only add regular files, symbolic links or git-directories", path);

	namelen = strlen(path);
	if (S_ISDIR(st.st_mode)) {
		while (namelen && path[namelen-1] == '/')
			namelen--;
	}
	size = cache_entry_size(namelen);
	ce = xcalloc(1, size);
	memcpy(ce->name, path, namelen);
	ce->ce_flags = namelen;
	fill_stat_cache_info(ce, &st);

	if (trust_executable_bit && has_symlinks)
		ce->ce_mode = create_ce_mode(st.st_mode);
	else {
		/* If there is an existing entry, pick the mode bits and type
		 * from it, otherwise assume unexecutable regular file.
