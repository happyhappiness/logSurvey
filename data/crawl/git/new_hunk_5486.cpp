		die("Missing author: %s",
		    sha1_to_hex(commit->object.sha1));
	if (log->user_format) {
		pretty_print_commit(CMIT_FMT_USERFORMAT, commit, &ufbuf,
			DEFAULT_ABBREV, "", "", DATE_NORMAL, 0);
		buffer = ufbuf.buf;
	} else if (*buffer) {
		buffer++;
	}
	insert_one_record(log, author, !*buffer ? "<none>" : buffer);
	strbuf_release(&ufbuf);
	strbuf_release(&buf);
}

static void get_from_rev(struct rev_info *rev, struct shortlog *log)
