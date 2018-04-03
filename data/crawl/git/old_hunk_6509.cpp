
const char *system_path(const char *path)
{
	static const char *prefix = PREFIX;
	struct strbuf d = STRBUF_INIT;

	if (is_absolute_path(path))
		return path;

	strbuf_addf(&d, "%s/%s", prefix, path);
	path = strbuf_detach(&d, NULL);
	return path;