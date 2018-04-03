		pretty_print_commit(rev.commit_format, commit, &out, &ctx);
	}
	if (write(fd, out.buf, out.len) < 0)
		die_errno(_("Writing SQUASH_MSG"));
	if (close(fd))
		die_errno(_("Finishing SQUASH_MSG"));
	strbuf_release(&out);
}

