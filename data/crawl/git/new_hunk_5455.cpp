test_expect_success 'without -trail' '

	git config core.whitespace -trail
	prepare_output

	grep Eight normal >/dev/null &&
	grep HT error >/dev/null &&
