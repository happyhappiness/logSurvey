	'

	test_expect_success 'non-fast-forward push shows help message' '
		test_i18ngrep "Updates were rejected because" output
	'
}
