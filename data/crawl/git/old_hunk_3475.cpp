	fi

	test_must_fail git "$cmd" "$GIT_DAEMON_URL/$repo" "$@" 2>output &&
	echo "fatal: remote error: $msg: /$repo" >expect &&
	test_cmp expect output
	ret=$?
	chmod +x "$GIT_DAEMON_DOCUMENT_ROOT_PATH/repo.git"
	(exit $ret)