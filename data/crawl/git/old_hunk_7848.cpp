	if (!dest || i != argc - 1)
		usage(peek_remote_usage);

	conn = git_connect(fd, dest, uploadpack, 0);
	ret = peek_remote(fd, flags);
	close(fd[0]);
	close(fd[1]);
	ret |= finish_connect(conn);
	return !!ret;
}
