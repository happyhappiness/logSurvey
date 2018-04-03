	add_pending_object(rev, branch, name);
	add_pending_object(rev, &head->object, "^HEAD");
	head->object.flags |= UNINTERESTING;
	prepare_revision_walk(rev);
	while ((commit = get_revision(rev)) != NULL) {
		char *oneline, *bol, *eol;

