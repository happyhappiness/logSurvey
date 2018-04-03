	return (write_err || status);
}

static int apply_filter(const char *path, const char *src, size_t len,
                        struct strbuf *dst, const char *cmd)
{
	/*
	 * Create a pipeline to have the command filter the buffer's
	 * contents.
	 *
	 * (child --> cmd) --> us
	 */
	int pipe_feed[2];
	int status, ret = 1;
	struct child_process child_process;
	struct strbuf nbuf;

	if (!cmd)
		return 0;

	memset(&child_process, 0, sizeof(child_process));

	if (pipe(pipe_feed) < 0) {
		error("cannot create pipe to run external filter %s", cmd);
		return 0;
	}

	fflush(NULL);
