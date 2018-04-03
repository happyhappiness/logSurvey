		   *author ? author : "nobody",
		   *author ? author : "nobody",
		   *uuid ? uuid : "local", timestamp);
	printf("data %"PRIuMAX"\n",
		(uintmax_t) (log->len + strlen(gitsvnline)));
	fwrite(log->buf, log->len, 1, stdout);
	printf("%s\n", gitsvnline);
	if (!first_commit_done) {