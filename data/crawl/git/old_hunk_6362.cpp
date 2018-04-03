
	ref = alloc_ref(refname);

	if (http_fetch_ref(remote->url, ref) != 0) {
		fprintf(stderr,
			"Unable to fetch ref %s from %s\n",
			refname, remote->url);
		free(ref);
		return;
	}
