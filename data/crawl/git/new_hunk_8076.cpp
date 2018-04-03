		error("cannot fork to run external filter %s", cmd);
		close(pipe_feed[0]);
		close(pipe_feed[1]);
		return 0;
	}
	if (!child_process.pid) {
		dup2(pipe_feed[1], 1);
		close(pipe_feed[0]);
		close(pipe_feed[1]);
		exit(filter_buffer(path, src, len, cmd));
	}
	close(pipe_feed[1]);

	strbuf_init(&nbuf, 0);
	if (strbuf_read(&nbuf, pipe_feed[0], len) < 0) {
		error("read from external filter %s failed", cmd);
		ret = 0;
	}
	if (close(pipe_feed[0])) {
		ret = error("read from external filter %s failed", cmd);
		ret = 0;
	}
	status = finish_command(&child_process);
	if (status) {
		ret = error("external filter %s failed %d", cmd, -status);
		ret = 0;
	}

	if (ret) {
		*dst = nbuf;
	} else {
		strbuf_release(&nbuf);
	}
	return ret;
}

static struct convert_driver {
