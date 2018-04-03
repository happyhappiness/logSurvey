	nargv[nargc] = NULL;

	fprintf(stderr,
		"*** \"git tar-tree\" is now deprecated.\n"
		"*** Running \"git archive\" instead.\n***");
	for (i = 0; i < nargc; i++) {
		fputc(' ', stderr);
		sq_quote_print(stderr, nargv[i]);
