	}

	if (sha_eq(common->object.sha1, merge->object.sha1)) {
		output(o, 0, "Already uptodate!");
		*result = head;
		return 1;
	}