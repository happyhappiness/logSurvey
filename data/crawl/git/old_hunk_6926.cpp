				die("multiple --exec specified");
			exec = arg + 7;
			exec_at = i;
			break;
		}
	}

	url = xstrdup(remote);
	conn = git_connect(fd, url, exec, 0);

	for (i = 1; i < argc; i++) {
		if (i == exec_at)
			continue;
		packet_write(fd[1], "argument %s\n", argv[i]);
	}
