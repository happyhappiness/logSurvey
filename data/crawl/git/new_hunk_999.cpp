	return !hashcmp(active_cache_tree->sha1, head_commit->tree->object.oid.hash);
}

/*
 * Read the author-script file into an environment block, ready for use in
 * run_command(), that can be free()d afterwards.
 */
static char **read_author_script(void)
{
	struct strbuf script = STRBUF_INIT;
	int i, count = 0;
	char *p, *p2, **env;
	size_t env_size;

	if (strbuf_read_file(&script, rebase_path_author_script(), 256) <= 0)
		return NULL;

	for (p = script.buf; *p; p++)
		if (skip_prefix(p, "'\\\\''", (const char **)&p2))
			strbuf_splice(&script, p - script.buf, p2 - p, "'", 1);
		else if (*p == '\'')
			strbuf_splice(&script, p-- - script.buf, 1, "", 0);
		else if (*p == '\n') {
			*p = '\0';
			count++;
		}

	env_size = (count + 1) * sizeof(*env);
	strbuf_grow(&script, env_size);
	memmove(script.buf + env_size, script.buf, script.len);
	p = script.buf + env_size;
	env = (char **)strbuf_detach(&script, NULL);

	for (i = 0; i < count; i++) {
		env[i] = p;
		p += strlen(p) + 1;
	}
	env[count] = NULL;

	return env;
}

/*
 * If we are cherry-pick, and if the merge did not result in
 * hand-editing, we will hit this commit and inherit the original
 * author date and name.
 *
 * If we are revert, or if our cherry-pick results in a hand merge,
 * we had better say that the current user is responsible for that.
 *
 * An exception is when run_git_commit() is called during an
 * interactive rebase: in that case, we will want to retain the
 * author metadata.
 */
static int run_git_commit(const char *defmsg, struct replay_opts *opts,
			  int allow_empty)
{
	char **env = NULL;
	struct argv_array array;
	int rc;
	const char *value;

	if (is_rebase_i(opts)) {
		env = read_author_script();
		if (!env)
			return error("You have staged changes in your working "
				"tree. If these changes are meant to be\n"
				"squashed into the previous commit, run:\n\n"
				"  git commit --amend $gpg_sign_opt_quoted\n\n"
				"If they are meant to go into a new commit, "
				"run:\n\n"
				"  git commit $gpg_sign_opt_quoted\n\n"
				"In both cases, once you're done, continue "
				"with:\n\n"
				"  git rebase --continue\n");
	}

	argv_array_init(&array);
	argv_array_push(&array, "commit");
	argv_array_push(&array, "-n");
