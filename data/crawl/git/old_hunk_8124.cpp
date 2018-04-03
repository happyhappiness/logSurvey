	if (oldval && *oldval && get_sha1(oldval, oldsha1))
		die("%s: not a valid old SHA1", oldval);

	lock = lock_any_ref_for_update(refname, oldval ? oldsha1 : NULL, ref_flags);
	if (!lock)
		die("%s: cannot lock the ref", refname);
	if (write_ref_sha1(lock, sha1, msg) < 0)
		die("%s: cannot update the ref", refname);
	return 0;
}
