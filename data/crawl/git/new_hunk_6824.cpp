	struct tree *mrtree = mrtree;
	int clean;

	if (show(o, 4)) {
		output(o, 4, "Merging:");
		output_commit_title(h1);
		output_commit_title(h2);
	}
