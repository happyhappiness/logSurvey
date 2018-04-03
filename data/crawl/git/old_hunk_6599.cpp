		pretty_print_commit(rev.commit_format, commit, &out, rev.abbrev,
			NULL, NULL, rev.date_mode, 0);
	}
	write(fd, out.buf, out.len);
	close(fd);
	strbuf_release(&out);
}

