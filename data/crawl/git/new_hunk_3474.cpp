	fi

	test_must_fail git "$cmd" "$GIT_DAEMON_URL/$repo" "$@" 2>output &&
	test_i18ngrep "fatal: remote error: $msg: /$repo" output &&
	ret=$?
	chmod +x "$GIT_DAEMON_DOCUMENT_ROOT_PATH/repo.git"
	(exit $ret)