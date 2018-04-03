	NULL
};

static void print_commit(char sign, struct commit *commit, int verbose,
			 int abbrev)
{
	if (!verbose) {
		printf("%c %s\n", sign,
		       find_unique_abbrev(commit->object.sha1, abbrev));
	} else {
		struct strbuf buf = STRBUF_INIT;
		struct pretty_print_context ctx = {0};
		pretty_print_commit(CMIT_FMT_ONELINE, commit, &buf, &ctx);
		printf("%c %s %s\n", sign,
		       find_unique_abbrev(commit->object.sha1, abbrev),
		       buf.buf);
		strbuf_release(&buf);
	}
}

int cmd_cherry(int argc, const char **argv, const char *prefix)
{
	struct rev_info revs;
