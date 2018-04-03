
		if (verbose) {
			struct strbuf buf = STRBUF_INIT;
			pretty_print_commit(CMIT_FMT_ONELINE, commit,
			                    &buf, 0, NULL, NULL, 0, 0);
			printf("%c %s %s\n", sign,
			       sha1_to_hex(commit->object.sha1), buf.buf);
			strbuf_release(&buf);
