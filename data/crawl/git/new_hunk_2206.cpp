	grep "relative path syntax can.t be used outside working tree." error
'

test_expect_success '<commit>:file correctly diagnosed after a pathname' '
	test_must_fail git rev-parse file.txt HEAD:file.txt 1>actual 2>error &&
	test_i18ngrep ! "exists on disk" error &&