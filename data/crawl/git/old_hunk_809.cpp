
	show_one(refname, oid);

	if (!deref_tags)
		return 0;

	if (!peel_ref(refname, peeled.hash)) {
		hex = find_unique_abbrev(peeled.hash, abbrev);
		printf("%s %s^{}\n", hex, refname);
	}
	return 0;
}

