		die("bad --ignore-submodules argument: %s", arg);
}

void show_submodule_summary(FILE *f, const char *path,
		unsigned char one[20], unsigned char two[20],
		unsigned dirty_submodule,
		const char *del, const char *add, const char *reset)
{
	struct rev_info rev;
	struct commit *commit, *left = left, *right = right;
	struct commit_list *merge_bases, *list;
	const char *message = NULL;
	struct strbuf sb = STRBUF_INIT;
	static const char *format = "  %m %s";
	int fast_forward = 0, fast_backward = 0;

	if (is_null_sha1(two))
