	 * bottom commits we would reach while traversing as
	 * uninteresting.
	 */
	if (prepare_revision_walk(&revs))
		die("revision walk setup failed");

	if (is_null_sha1(sb.final->object.sha1)) {
		char *buf;
