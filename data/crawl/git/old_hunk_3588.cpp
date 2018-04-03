	}
}

static struct lock_file packlock;

int pack_refs(unsigned int flags)
{
	struct pack_refs_cb_data cbdata;
	int fd;

	memset(&cbdata, 0, sizeof(cbdata));
	cbdata.flags = flags;

	fd = hold_lock_file_for_update(&packlock, git_path("packed-refs"),
				       LOCK_DIE_ON_ERROR);
	cbdata.packed_refs = get_packed_refs(&ref_cache);

	do_for_each_entry_in_dir(get_loose_refs(&ref_cache), 0,
				 pack_if_possible_fn, &cbdata);

	write_or_die(fd, PACKED_REFS_HEADER, strlen(PACKED_REFS_HEADER));
	do_for_each_entry_in_dir(cbdata.packed_refs, 0, write_packed_entry_fn, &fd);

	if (commit_lock_file(&packlock) < 0)
		die_errno("unable to overwrite old ref-pack file");
	prune_refs(cbdata.ref_to_prune);
	return 0;
}
