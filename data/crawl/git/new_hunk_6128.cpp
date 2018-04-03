		die("git archive: expected a flush");

	/* Now, start reading from fd[0] and spit it out to stdout */
	rv = recv_sideband("archive", fd[0], 1);
	close(fd[0]);
	close(fd[1]);
	rv |= finish_connect(conn);

	return !!rv;
}

#define PARSE_OPT_KEEP_ALL ( PARSE_OPT_KEEP_DASHDASH | 	\
			     PARSE_OPT_KEEP_ARGV0 | 	\
			     PARSE_OPT_KEEP_UNKNOWN |	\
			     PARSE_OPT_NO_INTERNAL_HELP	)

int cmd_archive(int argc, const char **argv, const char *prefix)
{
	const char *exec = "git-upload-archive";
	const char *output = NULL;
	const char *remote = NULL;
	struct option local_opts[] = {
		OPT_STRING(0, "output", &output, "file",
			"write the archive to this file"),
		OPT_STRING(0, "remote", &remote, "repo",
			"retrieve the archive from remote repository <repo>"),
		OPT_STRING(0, "exec", &exec, "cmd",
			"path to the remote git-upload-archive command"),
		OPT_END()
	};

	argc = parse_options(argc, argv, local_opts, NULL, PARSE_OPT_KEEP_ALL);

	if (output)
		create_output_file(output);

	if (remote)
		return run_remote_archiver(argc, argv, remote, exec);

	setvbuf(stderr, NULL, _IOLBF, BUFSIZ);

