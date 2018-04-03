	return clean;
}

int merge_recursive_config(const char *var, const char *value, void *cb)
{
	if (!strcasecmp(var, "merge.verbosity")) {
