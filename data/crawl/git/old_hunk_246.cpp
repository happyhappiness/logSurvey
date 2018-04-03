static const char PACKED_REFS_HEADER[] =
	"# pack-refs with: peeled fully-peeled \n";

/*
 * Write the current version of the packed refs cache from memory to
 * disk. The packed-refs file must already be locked for writing (see
 * packed_refs_lock()). Return zero on success. On errors, rollback
 * the lockfile, write an error message to `err`, and return a nonzero
 * value.
 */
int commit_packed_refs(struct ref_store *ref_store, struct strbuf *err)
{
	struct packed_ref_store *refs =
		packed_downcast(ref_store, REF_STORE_WRITE | REF_STORE_MAIN,
				"commit_packed_refs");
	struct packed_ref_cache *packed_ref_cache =
		get_packed_ref_cache(refs);
	int ok;
	int ret = -1;
	struct strbuf sb = STRBUF_INIT;
	FILE *out;
	struct ref_iterator *iter;
	char *packed_refs_path;

	if (!is_lock_file_locked(&refs->lock))
		die("BUG: commit_packed_refs() called when unlocked");

	/*
	 * If packed-refs is a symlink, we want to overwrite the
	 * symlinked-to file, not the symlink itself. Also, put the
	 * staging file next to it:
	 */
	packed_refs_path = get_locked_file_path(&refs->lock);
	strbuf_addf(&sb, "%s.new", packed_refs_path);
	if (create_tempfile(&refs->tempfile, sb.buf) < 0) {
		strbuf_addf(err, "unable to create file %s: %s",
			    sb.buf, strerror(errno));
		strbuf_release(&sb);
		goto out;
	}
	strbuf_release(&sb);

	out = fdopen_tempfile(&refs->tempfile, "w");
	if (!out) {
		strbuf_addf(err, "unable to fdopen packed-refs tempfile: %s",
			    strerror(errno));
		goto error;
	}

	if (fprintf(out, "%s", PACKED_REFS_HEADER) < 0) {
		strbuf_addf(err, "error writing to %s: %s",
			    get_tempfile_path(&refs->tempfile), strerror(errno));
		goto error;
	}

	iter = cache_ref_iterator_begin(packed_ref_cache->cache, NULL, 0);
	while ((ok = ref_iterator_advance(iter)) == ITER_OK) {
		struct object_id peeled;
		int peel_error = ref_iterator_peel(iter, &peeled);

		if (write_packed_entry(out, iter->refname, iter->oid->hash,
				       peel_error ? NULL : peeled.hash)) {
			strbuf_addf(err, "error writing to %s: %s",
				    get_tempfile_path(&refs->tempfile),
				    strerror(errno));
			ref_iterator_abort(iter);
			goto error;
		}
	}

	if (ok != ITER_DONE) {
		strbuf_addf(err, "unable to rewrite packed-refs file: "
			    "error iterating over old contents");
		goto error;
	}

	if (rename_tempfile(&refs->tempfile, packed_refs_path)) {
		strbuf_addf(err, "error replacing %s: %s",
			    refs->path, strerror(errno));
		goto out;
	}

	ret = 0;
	goto out;

error:
	delete_tempfile(&refs->tempfile);

out:
	free(packed_refs_path);
	return ret;
}

/*
 * Rewrite the packed-refs file, omitting any refs listed in
 * 'refnames'. On error, leave packed-refs unchanged, write an error
 * message to 'err', and return a nonzero value. The packed refs lock
 * must be held when calling this function; it will still be held when
 * the function returns.
 *
 * The refs in 'refnames' needn't be sorted. `err` must not be NULL.
 */
int repack_without_refs(struct ref_store *ref_store,
			struct string_list *refnames, struct strbuf *err)
{
	struct packed_ref_store *refs =
		packed_downcast(ref_store, REF_STORE_WRITE | REF_STORE_MAIN,
				"repack_without_refs");
	struct ref_dir *packed;
	struct string_list_item *refname;
	int needs_repacking = 0, removed = 0;

	packed_assert_main_repository(refs, "repack_without_refs");
	assert(err);

	if (!is_lock_file_locked(&refs->lock))
		die("BUG: repack_without_refs called without holding lock");

	/* Look for a packed ref */
	for_each_string_list_item(refname, refnames) {
		if (get_packed_ref(refs, refname->string)) {
			needs_repacking = 1;
			break;
		}
	}

	/* Avoid locking if we have nothing to do */
	if (!needs_repacking)
		return 0; /* no refname exists in packed refs */

	packed = get_packed_refs(refs);

	/* Remove refnames from the cache */
	for_each_string_list_item(refname, refnames)
		if (remove_entry_from_dir(packed, refname->string) != -1)
			removed = 1;
	if (!removed) {
		/*
		 * All packed entries disappeared while we were
		 * acquiring the lock.
		 */
		clear_packed_ref_cache(refs);
		return 0;
	}

	/* Write what remains */
	return commit_packed_refs(&refs->base, err);
}

static int packed_init_db(struct ref_store *ref_store, struct strbuf *err)
{
	/* Nothing to do. */
