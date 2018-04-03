	 */
	signal(SIGCHLD, SIG_DFL);

	protocol = parse_connect_url(url, &host, &path);
	if (flags & CONNECT_DIAG_URL) {
		printf("Diag: url=%s\n", url ? url : "NULL");
		printf("Diag: protocol=%s\n", prot_name(protocol));
		printf("Diag: hostandport=%s\n", host ? host : "NULL");
		printf("Diag: path=%s\n", path ? path : "NULL");
		free(host);
		free(path);
		return NULL;
	}
