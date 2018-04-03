	git_config(submodule_config, NULL);
}

static int gitmodules_cb(const char *var, const char *value, void *data)
{
	struct repository *repo = data;
