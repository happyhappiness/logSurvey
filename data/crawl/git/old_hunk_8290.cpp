			sign = '-';

		if (verbose) {
			static char buf[16384];
			pretty_print_commit(CMIT_FMT_ONELINE, commit, ~0,
			                    buf, sizeof(buf), 0, NULL, NULL, 0);
			printf("%c %s %s\n", sign,
			       sha1_to_hex(commit->object.sha1), buf);
		}
		else {
			printf("%c %s\n", sign,
