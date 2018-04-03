	}

	if (!match_cnt) {
		const unsigned char *sha1 = cmit->object.sha1;
		if (always) {
			printf("%s", find_unique_abbrev(sha1, abbrev));
			if (dirty)
				printf("%s", dirty);
			printf("\n");
