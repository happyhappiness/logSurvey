{
	fprintf(stderr, " %c %-*s ", flag, SUMMARY_WIDTH, summary);
	if (from)
		fprintf(stderr, "%s -> %s", prettify_refname(from->name), prettify_refname(to->name));
	else
		fputs(prettify_refname(to->name), stderr);
	if (msg) {
		fputs(" (", stderr);
		fputs(msg, stderr);