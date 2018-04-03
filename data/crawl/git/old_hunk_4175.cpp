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
