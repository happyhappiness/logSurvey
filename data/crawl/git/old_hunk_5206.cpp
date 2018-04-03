	return 0;
}

static int revert_or_cherry_pick(int argc, const char **argv)
{
	git_config(git_default_config, NULL);
	me = action == REVERT ? "revert" : "cherry-pick";
	setenv(GIT_REFLOG_ACTION, me, 0);
