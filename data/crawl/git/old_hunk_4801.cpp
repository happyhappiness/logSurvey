	return content_offset;
}

uint32_t repo_copy(uint32_t revision, uint32_t *src, uint32_t *dst)
{
	uint32_t mode = 0, content_offset = 0;
	struct repo_dirent *src_dent;
