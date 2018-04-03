		die("Branch is renamed, but update of config-file failed");
}

int cmd_branch(int argc, const char **argv, const char *prefix)
{
	int delete = 0, rename = 0, force_create = 0;
	int verbose = 0, abbrev = DEFAULT_ABBREV, detached = 0;
	int reflog = 0, track;
	int kinds = REF_LOCAL_BRANCH;

	struct option options[] = {
		OPT_GROUP("Generic options"),
