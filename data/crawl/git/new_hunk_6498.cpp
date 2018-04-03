		result = remove_branches(&branches);
	string_list_clear(&branches, 1);

	if (skipped.nr) {
		fprintf(stderr, skipped.nr == 1 ?
			"Note: A non-remote branch was not removed; "
			"to delete it, use:\n" :
			"Note: Non-remote branches were not removed; "
			"to delete them, use:\n");
		for (i = 0; i < skipped.nr; i++)
			fprintf(stderr, "  git branch -d %s\n",
				skipped.items[i].string);
	}
	string_list_clear(&skipped, 0);

	return result;
}

