
static void check_whitespace(const char *line, int len, unsigned ws_rule)
{
	char *err;
	unsigned result = check_and_emit_line(line + 1, len - 1, ws_rule,
	    NULL, NULL, NULL, NULL);
	if (!result)
		return;

	whitespace_error++;
	if (squelch_whitespace_errors &&
	    squelch_whitespace_errors < whitespace_error)
		;
	else {
		err = whitespace_error_string(result);
		fprintf(stderr, "%s.\n%s:%d:%.*s\n",
		     err, patch_input_file, linenr, len - 2, line + 1);
		free(err);
	}
}

/*
