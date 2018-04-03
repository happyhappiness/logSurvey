 * We optimistically assume that the directories exist,
 * which is true 99% of the time anyway. If they don't,
 * we create them and try again.
 */
static void create_one_file(struct apply_state *state,
			    char *path,
			    unsigned mode,
			    const char *buf,
			    unsigned long size)
{
	int res;

	if (state->cached)
		return;

	res = try_create_file(path, mode, buf, size);
	if (res < 0)
		exit(128);
	if (!res)
		return;

	if (errno == ENOENT) {
		if (safe_create_leading_directories(path))
			return;
		res = try_create_file(path, mode, buf, size);
		if (res < 0)
			exit(128);
		if (!res)
			return;
	}

	if (errno == EEXIST || errno == EACCES) {
