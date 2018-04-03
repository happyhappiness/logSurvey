	if (root && *root) {
		if (!pathinfo || !*pathinfo)
			die("GIT_PROJECT_ROOT is set but PATH_INFO is not");
		if (daemon_avoid_alias(pathinfo))
			die("'%s': aliased", pathinfo);
		strbuf_addstr(&buf, root);
		if (buf.buf[buf.len - 1] != '/')
			strbuf_addch(&buf, '/');
		if (pathinfo[0] == '/')
			pathinfo++;
		strbuf_addstr(&buf, pathinfo);
		return strbuf_detach(&buf, NULL);
	} else if (path && *path) {
