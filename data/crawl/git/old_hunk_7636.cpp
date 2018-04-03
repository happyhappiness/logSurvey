	int len;
	char *ref_info;

	if (fetch_ref(ls->dentry_name, remote_sha1) != 0) {
		fprintf(stderr,
			"Unable to fetch ref %s from %s\n",
			ls->dentry_name, remote->url);
