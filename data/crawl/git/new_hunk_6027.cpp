				       output_directory));
}

static const char * const builtin_format_patch_usage[] = {
	"git format-patch [options] [<since> | <revision range>]",
	NULL
};

static int keep_subject = 0;

static int keep_callback(const struct option *opt, const char *arg, int unset)
{
	((struct rev_info *)opt->value)->total = -1;
	keep_subject = 1;
	return 0;
}

static int subject_prefix = 0;

static int subject_prefix_callback(const struct option *opt, const char *arg,
			    int unset)
{
	subject_prefix = 1;
	((struct rev_info *)opt->value)->subject_prefix = arg;
	return 0;
}

static int numbered_callback(const struct option *opt, const char *arg,
			     int unset)
{
	*(int *)opt->value = unset ? 0 : 1;
	if (unset)
		auto_number =  0;
	return 0;
}

static int no_numbered_callback(const struct option *opt, const char *arg,
				int unset)
{
	return numbered_callback(opt, arg, 1);
}

static int output_directory_callback(const struct option *opt, const char *arg,
			      int unset)
{
	const char **dir = (const char **)opt->value;
	if (*dir)
		die("Two output directories?");
	*dir = arg;
	return 0;
}

static int thread_callback(const struct option *opt, const char *arg, int unset)
{
	int *thread = (int *)opt->value;
	if (unset)
		*thread = 0;
	else if (!arg || !strcmp(arg, "shallow"))
		*thread = THREAD_SHALLOW;
	else if (!strcmp(arg, "deep"))
		*thread = THREAD_DEEP;
	else
		return 1;
	return 0;
}

static int attach_callback(const struct option *opt, const char *arg, int unset)
{
	struct rev_info *rev = (struct rev_info *)opt->value;
	if (unset)
		rev->mime_boundary = NULL;
	else if (arg)
		rev->mime_boundary = arg;
	else
		rev->mime_boundary = git_version_string;
	rev->no_inline = unset ? 0 : 1;
	return 0;
}

static int inline_callback(const struct option *opt, const char *arg, int unset)
{
	struct rev_info *rev = (struct rev_info *)opt->value;
	if (unset)
		rev->mime_boundary = NULL;
	else if (arg)
		rev->mime_boundary = arg;
	else
		rev->mime_boundary = git_version_string;
	rev->no_inline = 0;
	return 0;
}

static int header_callback(const struct option *opt, const char *arg, int unset)
{
	add_header(arg);
	return 0;
}

static int cc_callback(const struct option *opt, const char *arg, int unset)
{
	ALLOC_GROW(extra_cc, extra_cc_nr + 1, extra_cc_alloc);
	extra_cc[extra_cc_nr++] = xstrdup(arg);
	return 0;
}

int cmd_format_patch(int argc, const char **argv, const char *prefix)
{
	struct commit *commit;
	struct commit **list = NULL;
	struct rev_info rev;
	int nr = 0, total, i;
	int use_stdout = 0;
	int start_number = -1;
	int numbered_files = 0;		/* _just_ numbers */
	int ignore_if_in_upstream = 0;
	int cover_letter = 0;
	int boundary_count = 0;
