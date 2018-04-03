pre_merge_head="$(git rev-parse HEAD)"

test_expect_success 'fails without MERGE_HEAD (unstarted merge)' '
	test_must_fail git merge --abort 2>output &&
	test_i18ngrep MERGE_HEAD output
'

test_expect_success 'fails without MERGE_HEAD (unstarted merge): .git/MERGE_HEAD sanity' '
