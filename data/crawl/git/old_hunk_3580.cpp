	(GIT_REMOTE_TESTGIT_FAILURE=1 &&
	export GIT_REMOTE_TESTGIT_FAILURE &&
	cd local &&
	test_must_fail git push --all 2> error &&
	cat error &&
	grep -q "Reading from helper .git-remote-testgit. failed" error
	)
'

