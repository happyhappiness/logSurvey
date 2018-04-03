static int prune_object(char *path, const char *filename, const unsigned char *sha1)
{
	const char *fullpath = mkpath("%s/%s", path, filename);
	if (expire) {
		struct stat st;
		if (lstat(fullpath, &st))
			return error("Could not stat '%s'", fullpath);
		if (st.st_mtime > expire)
			return 0;
	}
	if (show_only || verbose) {
		enum object_type type = sha1_object_info(sha1, NULL);
		printf("%s %s\n", sha1_to_hex(sha1),
