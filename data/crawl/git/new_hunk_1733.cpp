	cd "$ROOT_PATH"/test_repo_clone &&
	test_commit no-progress &&
	test_terminal git push --no-progress >output 2>&1 &&
	test_i18ngrep "^To http" output &&
	test_i18ngrep ! "^Writing objects"
'

test_expect_success 'push --progress shows progress to non-tty' '
	cd "$ROOT_PATH"/test_repo_clone &&
	test_commit progress &&
	git push --progress >output 2>&1 &&
	test_i18ngrep "^To http" output &&
	test_i18ngrep "^Writing objects" output
'

test_expect_success 'http push gives sane defaults to reflog' '