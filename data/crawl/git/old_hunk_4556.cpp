		pretty_print_commit(rev.commit_format, commit, &out, &ctx);
	}
	if (write(fd, out.buf, out.len) < 0)
		die_errno("Writing SQUASH_MSG");
	if (close(fd))
		die_errno("Finishing SQUASH_MSG");
	strbuf_release(&out);
}

