		pretty_print_commit(revs.commit_format, commit, ~0,
				    &buf, &buflen,
				    revs.abbrev, NULL, NULL, revs.date_mode);
		printf("%s%c", buf, hdr_termination);
		free(buf);
	}
	maybe_flush_or_die(stdout, "stdout");
