		ret = -1;
		goto free_return;
	}
	if (!hashcmp(ce_2->sha1, ce_3->sha1) &&
	    ce_2->ce_mode == ce_3->ce_mode) {
		fprintf(stderr, "%s: identical in both, skipping.\n",
			path);
