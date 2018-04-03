{
	int tret;
	if (waitpid(pid, &tret, 0) < 0) {
		error_errno("%s process failed to wait", name);
		return 1;
	}
	if (!WIFEXITED(tret) || WEXITSTATUS(tret)) {