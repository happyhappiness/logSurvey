	echo "update fail" >>file &&
	git commit -a -m "update fail" &&
	git rev-parse --verify testgit/origin/heads/update >expect &&
	GIT_REMOTE_TESTGIT_PUSH_ERROR="non-fast forward" &&
	export GIT_REMOTE_TESTGIT_PUSH_ERROR &&
	test_expect_code 1 git push origin update &&
	git rev-parse --verify testgit/origin/heads/update >actual &&
	test_cmp expect actual
	)
'

test_expect_success 'proper failure checks for fetching' '
	(GIT_REMOTE_TESTGIT_FAILURE=1 &&
	export GIT_REMOTE_TESTGIT_FAILURE &&
	cd local &&
	test_must_fail git fetch 2> error &&
	cat error &&
	grep -q "Error while running fast-import" error
	)
'

test_expect_success 'proper failure checks for pushing' '
	(cd local &&
	test_must_fail env GIT_REMOTE_TESTGIT_FAILURE=1 git push --all
	)
'

