		pretty_print_commit(rev.commit_format, commit, &out, rev.abbrev,
			NULL, NULL, rev.date_mode, 0);
	}
	if (write(fd, out.buf, out.len) < 0)
		die("Writing SQUASH_MSG: %s", strerror(errno));
	if (close(fd))
		die("Finishing SQUASH_MSG: %s", strerror(errno));
	strbuf_release(&out);
}

