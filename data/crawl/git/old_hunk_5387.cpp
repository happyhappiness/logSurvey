		exit(1);
	}

	bisect_rev = revs.commits->item->object.sha1;
	memcpy(bisect_rev_hex, sha1_to_hex(bisect_rev), 41);

