		if (!no_commit)
			res = run_git_commit(defmsg);
		if (!res)
			fprintf(stderr, "Finished one %s.\n", mebuf.buf);
	}

	strbuf_release(&mebuf);
