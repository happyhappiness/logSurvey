{
	int tret;
	if (waitpid(pid, &tret, 0) < 0) {
		error("%s process failed to wait: %s", name, strerror(errno));
		return 1;
	}
	if (!WIFEXITED(tret) || WEXITSTATUS(tret)) {