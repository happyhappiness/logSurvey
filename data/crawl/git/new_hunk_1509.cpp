 * We optimistically assume that the directories exist,
 * which is true 99% of the time anyway. If they don't,
 * we create them and try again.
 *
 * Returns:
 *   -1 on error
 *   0 otherwise
 */
static int create_one_file(struct apply_state *state,
			   char *path,
			   unsigned mode,
			   const char *buf,
			   unsigned long size)
{
	int res;

	if (state->cached)
		return 0;

	res = try_create_file(path, mode, buf, size);
	if (res < 0)
		return -1;
	if (!res)
		return 0;

	if (errno == ENOENT) {
		if (safe_create_leading_directories(path))
			return 0;
		res = try_create_file(path, mode, buf, size);
		if (res < 0)
			return -1;
		if (!res)
			return 0;
	}

	if (errno == EEXIST || errno == EACCES) {
