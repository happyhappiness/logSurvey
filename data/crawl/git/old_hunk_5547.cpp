	die("git fetch_pack: expected ACK/NAK, got '%s'", line);
}

static int find_common(int fd[2], unsigned char *result_sha1,
		       struct ref *refs)
{
