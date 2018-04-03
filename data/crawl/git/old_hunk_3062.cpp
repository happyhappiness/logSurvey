	return 0;
}

static int add(int ac, const char **av, const char *prefix)
{
	struct child_process c;
	int force = 0, detach = 0;
	const char *new_branch = NULL, *new_branch_force = NULL;
	const char *path, *branch;
