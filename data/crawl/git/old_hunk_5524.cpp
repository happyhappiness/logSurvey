	if (root && *root) {
		if (!pathinfo || !*pathinfo)
			die("GIT_PROJECT_ROOT is set but PATH_INFO is not");
		strbuf_addstr(&buf, root);
		strbuf_addstr(&buf, pathinfo);
		return strbuf_detach(&buf, NULL);
	} else if (path && *path) {
