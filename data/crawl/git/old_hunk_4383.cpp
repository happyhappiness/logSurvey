		commit = list->item;
		if (has_commit_patch_id(commit, &ids))
			sign = '-';

		if (verbose) {
			struct strbuf buf = STRBUF_INIT;
			struct pretty_print_context ctx = {0};
			pretty_print_commit(CMIT_FMT_ONELINE, commit,
					    &buf, &ctx);
			printf("%c %s %s\n", sign,
			       find_unique_abbrev(commit->object.sha1, abbrev),
			       buf.buf);
			strbuf_release(&buf);
		}
		else {
			printf("%c %s\n", sign,
			       find_unique_abbrev(commit->object.sha1, abbrev));
		}

		list = list->next;
	}
