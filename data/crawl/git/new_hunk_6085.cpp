	 */
	ret |= repack_without_ref(refname);

	unlink_or_warn(git_path("logs/%s", lock->ref_name));
	invalidate_cached_refs();
	unlock_ref(lock);
	return ret;
