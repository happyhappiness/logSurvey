	test_must_fail git log :!does-not-exist
'

test_expect_success '"git log :(exclude)sub" is not ambiguous' '
	git log ":(exclude)sub"
'

test_expect_success '"git log :(exclude)sub --" must resolve as an object' '
	test_must_fail git log ":(exclude)sub" --
'

test_expect_success '"git log :(unknown-magic) complains of bogus magic' '
	test_must_fail git log ":(unknown-magic)" 2>error &&
	test_i18ngrep pathspec.magic error
'

test_expect_success 'command line pathspec parsing for "git log"' '
	git reset --hard &&
	>a &&