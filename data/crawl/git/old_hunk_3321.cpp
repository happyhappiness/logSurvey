	return ecbdata.hit;
}

static void diffcore_pickaxe_grep(struct diff_options *o)
{
	int err;
	regex_t regex;
	int cflags = REG_EXTENDED | REG_NEWLINE;

	if (DIFF_OPT_TST(o, PICKAXE_IGNORE_CASE))
		cflags |= REG_ICASE;

	err = regcomp(&regex, o->pickaxe, cflags);
	if (err) {
		char errbuf[1024];
		regerror(err, &regex, errbuf, 1024);
		regfree(&regex);
		die("invalid regex: %s", errbuf);
	}

	pickaxe(&diff_queued_diff, o, &regex, NULL, diff_grep);

	regfree(&regex);
	return;
}

static unsigned int contains(mmfile_t *mf, regex_t *regexp, kwset_t kws)
{
	unsigned int cnt;
