	 * bottom commits we would reach while traversing as
	 * uninteresting.
	 */
	prepare_revision_walk(&revs);

	if (is_null_sha1(sb.final->object.sha1)) {
		char *buf;
