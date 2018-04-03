{
	struct commit *commit;

	if (prepare_revision_walk(rev))
		die("revision walk setup failed");
	while ((commit = get_revision(rev)) != NULL) {
		const char *author = NULL, *buffer;

