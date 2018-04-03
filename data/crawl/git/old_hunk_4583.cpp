pre_merge_head="$(git rev-parse HEAD)"

test_expect_success 'fails without MERGE_HEAD (unstarted merge)' '
	test_must_fail git merge --abort 2>output &&
	grep -q MERGE_HEAD output &&
	test ! -f .git/MERGE_HEAD &&
	test "$pre_merge_head" = "$(git rev-parse HEAD)"
'
