		die("Could not parse object '%s'.", rev);
	hashcpy(sha1, commit->object.sha1);

	/* git reset tree [--] paths... can be used to
	 * load chosen paths from the tree into the index without
	 * affecting the working tree nor HEAD. */
