
	if (msg) {
		fprintf(stderr, "%s\n", msg);
		return;
	}

	advise("after resolving the conflicts, mark the corrected paths");
	advise("with 'git add <paths>' or 'git rm <paths>'");

	if (action == CHERRY_PICK)
		advise("and commit the result with 'git commit -c %s'",
		       find_unique_abbrev(commit->object.sha1, DEFAULT_ABBREV));
}

static void write_message(struct strbuf *msgbuf, const char *filename)
