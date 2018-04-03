	return isalnum(ch) || ch == '_';
}

static void show_name(struct grep_opt *opt, const char *name)
{
	printf("%s%c", name, opt->null_following_name ? '\0' : '\n');
