	free_commit_list(result);
}

/*
 * This function runs the command "git rev-list $_good ^$_bad"
 * and returns 1 if it produces some output, 0 otherwise.
 */
static int check_ancestors(void)
{
	struct argv_array rev_argv = { NULL, 0, 0 };
	struct strbuf str = STRBUF_INIT;
	int i, result = 0;
	struct child_process rls;
	FILE *rls_fout;

	argv_array_push(&rev_argv, xstrdup("rev-list"));
	argv_array_push_sha1(&rev_argv, current_bad_sha1, "^%s");
	for (i = 0; i < good_revs.sha1_nr; i++)
		argv_array_push_sha1(&rev_argv, good_revs.sha1[i], "%s");
	argv_array_push(&rev_argv, NULL);

	memset(&rls, 0, sizeof(rls));
	rls.argv = rev_argv.argv;
	rls.out = -1;
	rls.git_cmd = 1;
	if (start_command(&rls))
		die("Could not launch 'git rev-list' command.");
	rls_fout = fdopen(rls.out, "r");
	while (strbuf_getline(&str, rls_fout, '\n') != EOF) {
		strbuf_trim(&str);
		if (*str.buf) {
			result = 1;
			break;
		}
	}
	fclose(rls_fout);
	finish_command(&rls);

	return result;
}

/*
