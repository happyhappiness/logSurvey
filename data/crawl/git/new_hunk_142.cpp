	run_rewrite_hook(&old_head->object.oid, new_head);
}

static int run_prepare_commit_msg_hook(struct strbuf *msg, const char *commit)
{
	struct argv_array hook_env = ARGV_ARRAY_INIT;
	int ret;
	const char *name;

	name = git_path_commit_editmsg();
	if (write_message(msg->buf, msg->len, name, 0))
		return -1;

	argv_array_pushf(&hook_env, "GIT_INDEX_FILE=%s", get_index_file());
	argv_array_push(&hook_env, "GIT_EDITOR=:");
	if (commit)
		ret = run_hook_le(hook_env.argv, "prepare-commit-msg", name,
				  "commit", commit, NULL);
	else
		ret = run_hook_le(hook_env.argv, "prepare-commit-msg", name,
				  "message", NULL);
	if (ret)
		ret = error(_("'prepare-commit-msg' hook failed"));
	argv_array_clear(&hook_env);

	return ret;
}

static const char implicit_ident_advice_noconfig[] =
N_("Your name and email address were configured automatically based\n"
"on your username and hostname. Please check that they are accurate.\n"
