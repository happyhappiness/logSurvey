			die("%s: not a valid SHA1", value);
	}

	if (oldval) {
		if (!*oldval)
			/*
			 * The empty string implies that the reference
			 * must not already exist:
			 */
			hashclr(oldsha1);
		else if (get_sha1(oldval, oldsha1))
			die("%s: not a valid old SHA1", oldval);
	}

	if (no_deref)
		flags = REF_NODEREF;