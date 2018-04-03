			mebuf.buf, help_msg());
		rerere(allow_rerere_auto);
	} else {
		if (!no_commit)
			res = run_git_commit(defmsg);
		if (!res)
			fprintf(stderr, "Finished one %s.\n", mebuf.buf);
	}

	strbuf_release(&mebuf);
	free_message(&msg);
	free(defmsg);

	return res;
}

static void prepare_revs(struct rev_info *revs)