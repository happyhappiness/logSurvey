static GIT_PATH_FUNC(rebase_path_strategy_opts, "rebase-merge/strategy_opts")
static GIT_PATH_FUNC(rebase_path_allow_rerere_autoupdate, "rebase-merge/allow_rerere_autoupdate")

static inline int is_rebase_i(const struct replay_opts *opts)
{
	return opts->action == REPLAY_INTERACTIVE_REBASE;
