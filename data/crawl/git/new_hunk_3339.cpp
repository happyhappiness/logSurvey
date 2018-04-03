
void install_branch_config(int flag, const char *local, const char *origin, const char *remote)
{
	const char *shortname = skip_prefix(remote, "refs/heads/");
	struct strbuf key = STRBUF_INIT;
	int rebasing = should_setup_rebase(origin);

	if (shortname
	    && !strcmp(local, shortname)
	    && !origin) {
		warning(_("Not setting branch %s as its own upstream."),