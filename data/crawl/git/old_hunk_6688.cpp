static const char check_attr_usage[] =
"git check-attr attr... [--] pathname...";

int cmd_check_attr(int argc, const char **argv, const char *prefix)
{
	struct git_attr_check *check;
