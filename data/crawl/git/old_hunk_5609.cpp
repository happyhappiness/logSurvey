	return commit->object.sha1;
}

static int find_common(int fd[2], unsigned char *result_sha1,
		       struct ref *refs)
{
