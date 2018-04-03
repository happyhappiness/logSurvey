	return strchr(url, ':') - url;
}

void transport_check_allowed(const char *type)
{
	struct string_list allowed = STRING_LIST_INIT_DUP;
	const char *v = getenv("GIT_ALLOW_PROTOCOL");

	if (!v)
		return;

	string_list_split(&allowed, v, ':', -1);
	if (!unsorted_string_list_has_string(&allowed, type))
		die("transport '%s' not allowed", type);
	string_list_clear(&allowed, 0);
}

struct transport *transport_get(struct remote *remote, const char *url)
{
	const char *helper;
