
static const char *bundle_usage="git-bundle (create <bundle> <git-rev-list args> | verify <bundle> | list-heads <bundle> [refname]... | unbundle <bundle> [refname]... )";

int cmd_bundle(int argc, const char **argv, const char *prefix)
{
	struct bundle_header header;
