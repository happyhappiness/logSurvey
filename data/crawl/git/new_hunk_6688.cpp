static const char check_attr_usage[] =
"git check-attr attr... [--] pathname...";

static void check_attr(int cnt, struct git_attr_check *check,
	const char** name, const char *file)
{
	int j;
	if (git_checkattr(file, cnt, check))
		die("git_checkattr died");
	for (j = 0; j < cnt; j++) {
		const char *value = check[j].value;

		if (ATTR_TRUE(value))
			value = "set";
		else if (ATTR_FALSE(value))
			value = "unset";
		else if (ATTR_UNSET(value))
			value = "unspecified";

		quote_c_style(file, NULL, stdout, 0);
		printf(": %s: %s\n", name[j], value);
	}
}

int cmd_check_attr(int argc, const char **argv, const char *prefix)
{
	struct git_attr_check *check;
