	close(fd[1]);
}

static char *locate_in_PATH(const char *file)
{
	const char *p = getenv("PATH");
