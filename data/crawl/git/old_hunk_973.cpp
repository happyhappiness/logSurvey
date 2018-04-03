		if (!env) {
			const char *gpg_opt = gpg_sign_opt_quoted(opts);

			return error("you have staged changes in your working "
				"tree. If these changes are meant to be\n"
				"squashed into the previous commit, run:\n\n"
				"  git commit --amend %s\n\n"
				"If they are meant to go into a new commit, "
				"run:\n\n"
				"  git commit %s\n\n"
				"In both cases, once you're done, continue "
				"with:\n\n"
				"  git rebase --continue\n", gpg_opt, gpg_opt);
		}
	}
