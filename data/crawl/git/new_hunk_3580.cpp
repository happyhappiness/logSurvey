	(GIT_REMOTE_TESTGIT_FAILURE=1 &&
	export GIT_REMOTE_TESTGIT_FAILURE &&
	cd local &&
	test_must_fail git push --all
	)
'

