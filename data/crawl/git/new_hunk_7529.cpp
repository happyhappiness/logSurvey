static const char write_tree_usage[] =
"git-write-tree [--missing-ok] [--prefix=<prefix>/]";

int cmd_write_tree(int argc, const char **argv, const char *unused_prefix)
{
	int missing_ok = 0, ret;
	const char *prefix = NULL;
	unsigned char sha1[20];
	const char *me = "git-write-tree";

	git_config(git_default_config);
	while (1 < argc) {
