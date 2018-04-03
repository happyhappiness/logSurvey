
#define SUBMODULE_PATCH_WITHOUT_INDEX 1

static int load_patch_target(struct strbuf *buf,
			     const struct cache_entry *ce,
			     struct stat *st,
			     const char *name,
			     unsigned expected_mode)
{
	if (cached || check_index) {
		if (read_file_or_gitlink(ce, buf))
			return error(_("read of %s failed"), name);
	} else if (name) {
		if (S_ISGITLINK(expected_mode)) {
			if (ce)
