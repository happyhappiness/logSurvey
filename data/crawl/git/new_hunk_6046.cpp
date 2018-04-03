	}
}

static void show_tried_revs(struct commit_list *tried)
{
	printf("bisect_tried='");
	print_commit_list(tried, "%s|", "%s");
	printf("'\n");
}

static void print_var_str(const char *var, const char *val)
{
	printf("%s='%s'\n", var, val);
}

static void print_var_int(const char *var, int val)
{
	printf("%s=%d\n", var, val);
}

int show_bisect_vars(struct rev_list_info *info, int reaches, int all)
{
	int cnt, flags = info->bisect_show_flags;
	char hex[41] = "";
	struct commit_list *tried;
	struct rev_info *revs = info->revs;
