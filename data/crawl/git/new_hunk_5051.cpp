	} else {
		if (!no_commit)
			res = run_git_commit(defmsg);
	}

	strbuf_release(&mebuf);
