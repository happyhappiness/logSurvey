			mebuf.buf, help_msg());
		rerere(allow_rerere_auto);
	} else {
		fprintf(stderr, "Finished one %s.\n", mebuf.buf);
	}

	strbuf_release(&mebuf);
	free_message(&msg);

	if (res)
		return 1;

	if (!no_commit) {
		res = run_git_commit(defmsg);
		free(defmsg);
		return res;
	}

	free(defmsg);

	return 0;
}

static void prepare_revs(struct rev_info *revs)