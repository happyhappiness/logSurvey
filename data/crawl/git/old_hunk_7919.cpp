	struct git_transport_data *data = transport->data;
	struct ref *refs;
	int fd[2];
	pid_t pid;
	char *dest = xstrdup(transport->url);

	pid = git_connect(fd, dest, data->uploadpack, 0);

	if (pid < 0)
		die("Failed to connect to \"%s\"", transport->url);

	get_remote_heads(fd[0], &refs, 0, NULL, 0);
	packet_flush(fd[1]);

	finish_connect(pid);

	free(dest);
