		}
	}

	strbuf_addstr(&mebuf, me);

	if (!strategy || !strcmp(strategy, "recursive") || action == REVERT) {
		res = do_recursive_merge(base, next, base_label, next_label,
					 head, &msgbuf);
		write_message(&msgbuf, defmsg);
	} else {
		struct commit_list *common = NULL;
		struct commit_list *remotes = NULL;

		strbuf_addf(&mebuf, " with strategy %s", strategy);
		write_message(&msgbuf, defmsg);

		commit_list_insert(base, &common);
		commit_list_insert(next, &remotes);
		res = try_merge_command(strategy, common,
					sha1_to_hex(head), remotes);
		free_commit_list(common);
		free_commit_list(remotes);
	}

	if (res) {
		fprintf(stderr, "Automatic %s failed.%s\n",
			mebuf.buf, help_msg());
		rerere(allow_rerere_auto);
	} else {
		fprintf(stderr, "Finished one %s.\n", mebuf.buf);
	}

	strbuf_release(&mebuf);
	free_message(&msg);

	if (res)
		return 1;

	/*
	 *
	 * If we are cherry-pick, and if the merge did not result in
