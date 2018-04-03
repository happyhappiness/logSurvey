		printf("%s%c", buf, hdr_termination);
		free(buf);
	}
	fflush(stdout);
	if (commit->parents) {
		free_commit_list(commit->parents);
		commit->parents = NULL;
