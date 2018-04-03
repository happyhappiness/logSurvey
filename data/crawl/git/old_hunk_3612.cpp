	return -1;
}

static int check_submodules_use_gitfiles(void)
{
	int i;
	int errs = 0;

	for (i = 0; i < list.nr; i++) {
		const char *name = list.entry[i].name;
