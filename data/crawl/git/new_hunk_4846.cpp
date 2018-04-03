
	if (msg) {
		fprintf(stderr, "%s\n", msg);
		/*
		 * A conflict has occured but the porcelain
		 * (typically rebase --interactive) wants to take care
		 * of the commit itself so remove CHERRY_PICK_HEAD
		 */
		unlink(git_path("CHERRY_PICK_HEAD"));
		return;
	}

	advise("after resolving the conflicts, mark the corrected paths");
	advise("with 'git add <paths>' or 'git rm <paths>'");

	if (action == CHERRY_PICK)
		advise("and commit the result with 'git commit -c CHERRY_PICK_HEAD'");
}

static void write_message(struct strbuf *msgbuf, const char *filename)
