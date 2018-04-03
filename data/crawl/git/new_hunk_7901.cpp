	 *
	 * (child --> cmd) --> us
	 */
	int ret = 1;
	struct strbuf nbuf;
	struct async async;
	struct filter_params params;

	if (!cmd)
		return 0;

	memset(&async, 0, sizeof(async));
	async.proc = filter_buffer;
	async.data = &params;
	params.src = src;
	params.size = len;
	params.cmd = cmd;

	fflush(NULL);
	if (start_async(&async))
		return 0;	/* error was already reported */

	strbuf_init(&nbuf, 0);
	if (strbuf_read(&nbuf, async.out, len) < 0) {
		error("read from external filter %s failed", cmd);
		ret = 0;
	}
	if (close(async.out)) {
		error("read from external filter %s failed", cmd);
		ret = 0;
	}
	if (finish_async(&async)) {
		error("external filter %s failed", cmd);
		ret = 0;
	}
