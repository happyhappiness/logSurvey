EOF


test_expect_success 'status without relative paths' '

	git config status.relativePaths false &&
	test_when_finished "git config --unset status.relativePaths" &&
	(cd dir1 && git status) >output &&
	test_i18ncmp expect output

'

