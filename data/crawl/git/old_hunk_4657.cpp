{
	struct commit *commit = lookup_commit(sha1);
	if (!commit || parse_commit(commit))
		die("could not parse HEAD commit");
	return !!(commit->parents && commit->parents->next);
}

