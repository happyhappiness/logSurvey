		}
	}

	return send_pack(&args, dest, remote, nr_heads, heads);
}

int send_pack(struct send_pack_args *my_args,
	      const char *dest, struct remote *remote,
	      int nr_heads, const char **heads)
{
	int fd[2], ret;
	struct child_process *conn;

	memcpy(&args, my_args, sizeof(args));

	verify_remote_names(nr_heads, heads);

	conn = git_connect(fd, dest, args.receivepack, args.verbose ? CONNECT_VERBOSE : 0);
	ret = do_send_pack(fd[0], fd[1], remote, dest, nr_heads, heads);
	close(fd[0]);
	/* do_send_pack always closes fd[1] */
	ret |= finish_connect(conn);
	return !!ret;
}
