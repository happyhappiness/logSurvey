	}
}

static char *prepare_index(int argc, const char **argv, const char *prefix)
{
	int fd;
	struct tree *tree;
	struct path_list partial;
	const char **pathspec = NULL;

