		if (!env) {
			const char *gpg_opt = gpg_sign_opt_quoted(opts);

			return error("you have staged changes in your working "
				"tree. If these changes are meant to be\n"
				"squashed into the previous commit, run:\n\n"
				"  git commit --amend %s\n\n"
