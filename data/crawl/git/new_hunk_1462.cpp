	if ((status < 0) || !result_buf.ptr)
		die("Failed to execute internal merge");

	write_buf_to_worktree(p->obj.hash, result_buf.ptr, result_buf.size);
	free(result_buf.ptr);

	return status;
