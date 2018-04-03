{
	struct commit *commit;

	prepare_revision_walk(rev);
	while ((commit = get_revision(rev)) != NULL) {
		const char *author = NULL, *buffer;

