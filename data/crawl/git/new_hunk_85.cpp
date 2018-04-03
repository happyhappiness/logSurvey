			free(gitfile);
			return NULL;
		}
		die(_("not a git repository: '%s'"), gitdirenv);
	}

	if (check_repository_format_gently(gitdirenv, repo_fmt, nongit_ok)) {
