	else if (contents_from)
		die("Cannot use --contents with final commit object name");

	/*
	 * If we have bottom, this will mark the ancestors of the
	 * bottom commits we would reach while traversing as
