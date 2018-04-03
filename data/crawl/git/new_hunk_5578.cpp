
		if (verbose) {
			struct strbuf buf = STRBUF_INIT;
			struct pretty_print_context ctx = {0};
			pretty_print_commit(CMIT_FMT_ONELINE, commit,
					    &buf, &ctx);
			printf("%c %s %s\n", sign,
			       sha1_to_hex(commit->object.sha1), buf.buf);
			strbuf_release(&buf);
