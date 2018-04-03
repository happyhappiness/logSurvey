		if (parse_commit(commit) != 0)
			printf("(bad commit)\n");
		else {
			const char *title;
			int len = find_commit_subject(commit->buffer, &title);
			if (len)
				printf("%.*s\n", len, title);
		}
	}
}