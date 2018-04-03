
int pack_refs(unsigned int flags)
{
	struct pack_refs_cb_data cbdata;

	memset(&cbdata, 0, sizeof(cbdata));
	cbdata.flags = flags;

	cbdata.fd = hold_lock_file_for_update(&packlock, git_path("packed-refs"),
					      LOCK_DIE_ON_ERROR);

	write_or_die(cbdata.fd, PACKED_REFS_HEADER, strlen(PACKED_REFS_HEADER));

	do_for_each_entry(NULL, "", pack_one_ref, &cbdata);
	if (commit_lock_file(&packlock) < 0)
		die_errno("unable to overwrite old ref-pack file");
	prune_refs(cbdata.ref_to_prune);