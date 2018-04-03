		exit(1);
	}

	if (!all) {
		fprintf(stderr, "No testable commit found.\n"
			"Maybe you started with bad path parameters?\n");
		exit(4);
	}

	bisect_rev = revs.commits->item->object.sha1;
	memcpy(bisect_rev_hex, sha1_to_hex(bisect_rev), 41);

