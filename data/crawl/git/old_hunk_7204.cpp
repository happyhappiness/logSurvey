		pretty_print_commit(revs.commit_format, commit,
				    &buf, revs.abbrev, NULL, NULL,
				    revs.date_mode, 0);
		if (buf.len)
			printf("%s%c", buf.buf, hdr_termination);
		strbuf_release(&buf);
	}
	maybe_flush_or_die(stdout, "stdout");
	finish_commit(commit);
