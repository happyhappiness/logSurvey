		ret = 0;
	}
	if (close(pipe_feed[0])) {
		error("read from external filter %s failed", cmd);
		ret = 0;
	}
	status = finish_command(&child_process);
	if (status) {
		error("external filter %s failed %d", cmd, -status);
		ret = 0;
	}

	if (ret) {
		strbuf_swap(dst, &nbuf);
	}
	strbuf_release(&nbuf);
	return ret;
}

