
static const char var_usage[] = "git var [-l | <variable>]";

struct git_var {
	const char *name;
	const char *(*read)(int);
};
static struct git_var git_vars[] = {
	{ "GIT_COMMITTER_IDENT", git_committer_info },
	{ "GIT_AUTHOR_IDENT",   git_author_info },
	{ "", NULL },
};

static void list_vars(void)
{
	struct git_var *ptr;
	for (ptr = git_vars; ptr->read; ptr++)
		printf("%s=%s\n", ptr->name, ptr->read(0));
}

static const char *read_var(const char *var)