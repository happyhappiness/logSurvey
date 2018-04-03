		char *buf, *sp, *eol;
		size_t len;

		if (!filter->lines) {
			printf("%s\n", refname);
			return 0;
