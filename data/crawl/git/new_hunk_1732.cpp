	cd "$ROOT_PATH"/test_repo_clone &&
	test_commit noisy &&
	test_terminal git push >output 2>&1 &&
	test_i18ngrep "^Writing objects" output
'

test_expect_success TTY 'push --quiet silences status and progress' '
