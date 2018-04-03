			}
			usage(fetch_pack_usage);
		}
		dest = (char *)arg;
		heads = (char **)(argv + i + 1);
		nr_heads = argc - i - 1;
		break;
	}
	if (!dest)
		usage(fetch_pack_usage);

	ref = fetch_pack(dest, nr_heads, heads);

	ret = !ref;

	while (ref) {
		printf("%s %s\n",
		       sha1_to_hex(ref->old_sha1), ref->name);
		ref = ref->next;
	}

	return ret;
}

struct ref *fetch_pack(const char *dest, int nr_heads, char **heads)
{
	int i, ret;
	int fd[2];
	pid_t pid;
	struct ref *ref;
	struct stat st;

	if (depth > 0) {
		if (stat(git_path("shallow"), &st))
			st.st_mtime = 0;
	}

	printf("connect to %s\n", dest);

	pid = git_connect(fd, (char *)dest, uploadpack,
                          verbose ? CONNECT_VERBOSE : 0);
	if (pid < 0)
		return NULL;
	if (heads && nr_heads)
		nr_heads = remove_duplicates(nr_heads, heads);
	ref = do_fetch_pack(fd, nr_heads, heads);
	close(fd[0]);
	close(fd[1]);
	ret = finish_connect(pid);

	if (!ret && nr_heads) {
		/* If the heads to pull were given, we should have
