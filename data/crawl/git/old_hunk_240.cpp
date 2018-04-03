	return 0;
}

static int check_has_commit(const struct object_id *oid, void *data)
{
	int *has_commit = data;

	if (!lookup_commit_reference(oid))
		*has_commit = 0;

	return 0;
}

static int submodule_has_commits(const char *path, struct oid_array *commits)
{
	int has_commit = 1;

	/*
	 * Perform a cheap, but incorrect check for the existence of 'commits'.
