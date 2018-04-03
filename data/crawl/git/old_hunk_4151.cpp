'

test_expect_success 'push fails for non-fast-forward refs unmatched by remote helper: our output' '
	test_i18ngrep "To prevent you from losing history, non-fast-forward updates were rejected" \
		output
'
