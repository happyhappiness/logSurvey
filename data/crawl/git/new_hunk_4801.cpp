	return content_offset;
}

uint32_t repo_read_mode(const uint32_t *path)
{
	struct repo_dirent *dent = repo_read_dirent(active_commit, path);
	if (dent == NULL)
		die("invalid dump: path to be modified is missing");
	return dent->mode;
}

void repo_copy(uint32_t revision, const uint32_t *src, const uint32_t *dst)
{
	uint32_t mode = 0, content_offset = 0;
	struct repo_dirent *src_dent;
