		die("git archive: expected a flush");

	/* Now, start reading from fd[0] and spit it out to stdout */
	rv = recv_sideband("archive", fd[0], 1, 2);
	close(fd[0]);
	close(fd[1]);
	rv |= finish_connect(conn);
