	cmd[i] = NULL;
}

int cmd_gc(int argc, const char **argv, const char *prefix)
{
	int i;
	int prune = 0;
	char buf[80];

	git_config(gc_config);
