	if (!deref_tags)
		return 0;

	if (!peel_ref(refname, peeled)) {
		hex = find_unique_abbrev(peeled, abbrev);
		printf("%s %s^{}\n", hex, refname);
	}
	return 0;
}
