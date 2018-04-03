		NULL
};

static int git_verify_tag_config(const char *var, const char *value, void *cb)
{
	int status = git_gpg_config(var, value, cb);
