	echo "update fail" >>file &&
	git commit -a -m "update fail" &&
	git rev-parse --verify testgit/origin/heads/update >expect &&
	test_expect_code 1 env GIT_REMOTE_TESTGIT_FAILURE="non-fast forward" \
		git push origin update &&
	git rev-parse --verify testgit/origin/heads/update >actual &&
	test_cmp expect actual
	)
'

clean_mark () {
	cut -f 2 -d ' ' "$1" |
	git cat-file --batch-check |
	grep commit |
	sort >$(basename "$1")
}

cmp_marks () {
	test_when_finished "rm -rf git.marks testgit.marks" &&
	clean_mark ".git/testgit/$1/git.marks" &&
	clean_mark ".git/testgit/$1/testgit.marks" &&
	test_cmp git.marks testgit.marks
}

test_expect_success 'proper failure checks for fetching' '
	(cd local &&
	test_must_fail env GIT_REMOTE_TESTGIT_FAILURE=1 git fetch 2>error &&
	cat error &&
	grep -q "Error while running fast-import" error
	)
'

test_expect_success 'proper failure checks for pushing' '
	(cd local &&
	git checkout -b crash master &&
	echo crash >>file &&
	git commit -a -m crash &&
	test_must_fail env GIT_REMOTE_TESTGIT_FAILURE=1 git push --all &&
	cmp_marks origin
	)
'

