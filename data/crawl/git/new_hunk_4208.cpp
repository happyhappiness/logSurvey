	git push --mirror "$HTTPD_URL"/smart/alternates-mirror.git
'

test_expect_success TTY 'quiet push' '
	cd "$ROOT_PATH"/test_repo_clone &&
	test_commit quiet &&
	test_terminal git push --quiet --no-progress 2>&1 | tee output &&
	test_cmp /dev/null output
'

stop_httpd
test_done