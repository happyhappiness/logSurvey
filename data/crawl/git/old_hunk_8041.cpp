			}
			usage(fetch_pack_usage);
		}
		dest = arg;
		heads = argv + i + 1;
		nr_heads = argc - i - 1;
		break;
	}
	if (!dest)
		usage(fetch_pack_usage);
	pid = git_connect(fd, dest, uploadpack, verbose ? CONNECT_VERBOSE : 0);
	if (pid < 0)
		return 1;
	if (heads && nr_heads)
		nr_heads = remove_duplicates(nr_heads, heads);
	ret = fetch_pack(fd, nr_heads, heads);
	close(fd[0]);
	close(fd[1]);
	ret |= finish_connect(pid);

	if (!ret && nr_heads) {
		/* If the heads to pull were given, we should have
