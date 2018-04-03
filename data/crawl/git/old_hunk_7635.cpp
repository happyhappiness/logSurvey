	struct object *obj;
	int len = strlen(refname) + 1;

	if (fetch_ref(refname, remote_sha1) != 0) {
		fprintf(stderr,
			"Unable to fetch ref %s from %s\n",
			refname, remote->url);
