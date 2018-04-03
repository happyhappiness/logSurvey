{
	int i;
	for (i = 0; i < q->nr; i++) {
		struct diff_filespec *spec = q->queue[i]->two;
		if (is_null_sha1(spec->sha1))
			printf("D %s\n", spec->path);
		else {
			/*
			 * Links refer to objects in another repositories;
			 * output the SHA-1 verbatim.
