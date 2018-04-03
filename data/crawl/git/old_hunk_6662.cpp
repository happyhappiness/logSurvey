		const char *refname = item->string;
		unsigned char *sha1 = item->util;

		if (delete_ref(refname, sha1))
			result |= error("Could not remove branch %s", refname);
	}
	return result;
