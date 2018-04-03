	return NULL;
}

int cmd_checkout(int argc, const char **argv, const char *prefix)
{
	struct checkout_opts opts;
	unsigned char rev[20], branch_rev[20];
	const char *arg;
	struct branch_info new;
	struct tree *source_tree = NULL;
	char *conflict_style = NULL;
