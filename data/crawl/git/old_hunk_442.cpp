
	if (!is_lock_file_locked(&refs->packed_refs_lock))
		die("BUG: packed refs not locked");
	add_ref_entry(get_packed_ref_dir(packed_ref_cache),
		      create_ref_entry(refname, oid, REF_ISPACKED, 1));
}

/*
