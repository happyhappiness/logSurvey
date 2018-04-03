	return (write_err || status);
}

static char *apply_filter(const char *path, const char *src,
			  unsigned long *sizep, const char *cmd)
{
	/*
	 * Create a pipeline to have the command filter the buffer's
	 * contents.
	 *
	 * (child --> cmd) --> us
	 */
	const int SLOP = 4096;
	int pipe_feed[2];
	int status;
	char *dst;
	unsigned long dstsize, dstalloc;
	struct child_process child_process;

	if (!cmd)
		return NULL;

	memset(&child_process, 0, sizeof(child_process));

	if (pipe(pipe_feed) < 0) {
		error("cannot create pipe to run external filter %s", cmd);
		return NULL;
	}

	fflush(NULL);
