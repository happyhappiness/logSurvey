	}

	if (!cmd)
		not_found(&hdr, "Request not supported: '%s'", dir);

	setup_path();
	if (!enter_repo(dir, 0))
		not_found(&hdr, "Not a git repository: '%s'", dir);
	if (!getenv("GIT_HTTP_EXPORT_ALL") &&
	    access("git-daemon-export-ok", F_OK) )
		not_found(&hdr, "Repository not exported: '%s'", dir);

	http_config();
	max_request_buffer = git_env_ulong("GIT_HTTP_MAX_REQUEST_BUFFER",
					   max_request_buffer);

	cmd->imp(&hdr, cmd_arg);
	return 0;
}