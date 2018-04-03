		char index[PATH_MAX];
		const char *env[2] = { index, NULL };
		snprintf(index, sizeof(index), "GIT_INDEX_FILE=%s", index_file);
		launch_editor(git_path(commit_editmsg), &sb, env);
	} else if (strbuf_read_file(&sb, git_path(commit_editmsg), 0) < 0) {
		rollback_index_files();
		die("could not read commit message");
	}
	if (!no_verify &&
	    run_hook(index_file, "commit-msg", git_path(commit_editmsg))) {
		rollback_index_files();
		exit(1);
	}

	/* Truncate the message just before the diff, if any. */
	p = strstr(sb.buf, "\ndiff --git a/");
