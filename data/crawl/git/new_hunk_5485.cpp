	grep "^Signed-off-by: $GIT_COMMITTER_NAME <$GIT_COMMITTER_EMAIL>"
'

test_expect_success 'format-patch -- <path>' '
	git format-patch master..side -- file 2>error &&
	! grep "Use .--" error
'

test_done