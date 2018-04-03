			git_tcp_connect(fd, host, flags);
		/*
		 * Separate original protocol components prog and path
		 * from extended components with a NUL byte.
		 */
		packet_write(fd[1],
			     "%s %s%chost=%s%c",
