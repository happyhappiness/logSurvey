	grep "fatal: Path '"'"'disk-only.txt'"'"' exists on disk, but not in the index." error
'

test_expect_success 'invalid @{n} reference' '
	test_must_fail git rev-parse master@{99999} >output 2>error &&
	test -z "$(cat output)" &&
	grep "fatal: Log for [^ ]* only has [0-9][0-9]* entries." error  &&
	test_must_fail git rev-parse --verify master@{99999} >output 2>error &&
	test -z "$(cat output)" &&
	grep "fatal: Log for [^ ]* only has [0-9][0-9]* entries." error
'

test_done