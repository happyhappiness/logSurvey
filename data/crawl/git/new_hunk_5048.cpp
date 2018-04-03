		      action == REVERT ? "revert" : "apply",
		      find_unique_abbrev(commit->object.sha1, DEFAULT_ABBREV),
		      msg.subject);
		print_advice();
		rerere(allow_rerere_auto);
	} else {
		if (!no_commit)
			res = run_git_commit(defmsg);
	}

	free_message(&msg);
	free(defmsg);

