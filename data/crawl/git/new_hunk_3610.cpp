{
	struct tree_desc one;
	struct tree_desc two;
	void *one_buf = fill_tree_desc_strict(&one, hash1);
	void *two_buf = fill_tree_desc_strict(&two, hash2);
	int score = 0;

	for (;;) {
		struct name_entry e1, e2;
		int got_entry_from_one = tree_entry(&one, &e1);
