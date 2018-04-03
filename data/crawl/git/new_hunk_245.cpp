	return get_packed_ref_dir(get_packed_ref_cache(refs));
}

/*
 * Return the ref_entry for the given refname from the packed
 * references.  If it does not exist, return NULL.
