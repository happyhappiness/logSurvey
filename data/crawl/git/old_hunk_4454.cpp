
	_remote = remote_get(remote);
	if (!_remote->url[0])
		die("git archive: Remote with no URL");
	transport = transport_get(_remote, _remote->url[0]);
	transport_connect(transport, "git-upload-archive", exec, fd);

