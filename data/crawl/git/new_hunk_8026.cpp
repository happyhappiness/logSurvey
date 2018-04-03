			st.st_mtime = 0;
	}

	pid = git_connect(fd, (char *)dest, uploadpack,
                          verbose ? CONNECT_VERBOSE : 0);
	if (pid < 0)
