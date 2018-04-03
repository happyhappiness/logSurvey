		die("%s: not a valid old SHA1", oldval);

	return update_ref(msg, refname, sha1, oldval ? oldsha1 : NULL,
			  no_deref ? REF_NODEREF : 0, DIE_ON_ERR);
}