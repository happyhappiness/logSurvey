		die("%s: not a valid old SHA1", oldval);

	return update_ref(msg, refname, sha1, oldval ? oldsha1 : NULL,
			  ref_flags, DIE_ON_ERR);
}