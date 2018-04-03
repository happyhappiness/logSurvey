{
	fprintf(stderr, " %c %-*s ", flag, SUMMARY_WIDTH, summary);
	if (from)
		fprintf(stderr, "%s -> %s", prettify_ref(from), prettify_ref(to));
	else
		fputs(prettify_ref(to), stderr);
	if (msg) {
		fputs(" (", stderr);
		fputs(msg, stderr);