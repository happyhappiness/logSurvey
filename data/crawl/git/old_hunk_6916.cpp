static const char merge_base_usage[] =
"git merge-base [--all] <commit-id> <commit-id>";

int cmd_merge_base(int argc, const char **argv, const char *prefix)
{
	struct commit *rev1, *rev2;
	unsigned char rev1key[20], rev2key[20];
	int show_all = 0;

	git_config(git_default_config, NULL);
