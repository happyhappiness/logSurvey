		     (stage == 2) ? "our" : "their");
}

/* NEEDSWORK: share with merge-recursive */
static void fill_mm(const unsigned char *sha1, mmfile_t *mm)
{
	unsigned long size;
	enum object_type type;

	if (!hashcmp(sha1, null_sha1)) {
		mm->ptr = xstrdup("");
		mm->size = 0;
		return;
	}

	mm->ptr = read_sha1_file(sha1, &type, &size);
	if (!mm->ptr || type != OBJ_BLOB)
		die("unable to read blob object %s", sha1_to_hex(sha1));
	mm->size = size;
}

static int checkout_merged(int pos, struct checkout *state)
{
	struct cache_entry *ce = active_cache[pos];
	const char *path = ce->name;
	mmfile_t ancestor, ours, theirs;
	int status;
	unsigned char sha1[20];
	mmbuffer_t result_buf;

	if (ce_stage(ce) != 1 ||
	    active_nr <= pos + 2 ||
	    strcmp(active_cache[pos+1]->name, path) ||
	    ce_stage(active_cache[pos+1]) != 2 ||
	    strcmp(active_cache[pos+2]->name, path) ||
	    ce_stage(active_cache[pos+2]) != 3)
		return error("path '%s' does not have all 3 versions", path);

	fill_mm(active_cache[pos]->sha1, &ancestor);
	fill_mm(active_cache[pos+1]->sha1, &ours);
	fill_mm(active_cache[pos+2]->sha1, &theirs);

	status = ll_merge(&result_buf, path, &ancestor,
			  &ours, "ours", &theirs, "theirs", 1);
	free(ancestor.ptr);
	free(ours.ptr);
	free(theirs.ptr);
	if (status < 0 || !result_buf.ptr) {
		free(result_buf.ptr);
		return error("path '%s': cannot merge", path);
	}

	/*
	 * NEEDSWORK:
	 * There is absolutely no reason to write this as a blob object
	 * and create a phoney cache entry just to leak.  This hack is
	 * primarily to get to the write_entry() machinery that massages
	 * the contents to work-tree format and writes out which only
	 * allows it for a cache entry.  The code in write_entry() needs
	 * to be refactored to allow us to feed a <buffer, size, mode>
	 * instead of a cache entry.  Such a refactoring would help
	 * merge_recursive as well (it also writes the merge result to the
	 * object database even when it may contain conflicts).
	 */
	if (write_sha1_file(result_buf.ptr, result_buf.size,
			    blob_type, sha1))
		die("Unable to add merge result for '%s'", path);
	ce = make_cache_entry(create_ce_mode(active_cache[pos+1]->ce_mode),
			      sha1,
			      path, 2, 0);
	status = checkout_entry(ce, state, NULL);
	return status;
}

static int checkout_paths(struct tree *source_tree, const char **pathspec,
			  struct checkout_opts *opts)
{
