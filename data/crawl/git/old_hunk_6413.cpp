static int match_name_with_pattern(const char *key, const char *name,
				   const char *value, char **result)
{
	size_t klen = strlen(key);
	int ret = !strncmp(key, name, klen);
	if (ret && value) {
		size_t vlen = strlen(value);
		*result = xmalloc(vlen +
				  strlen(name) -
				  klen + 1);