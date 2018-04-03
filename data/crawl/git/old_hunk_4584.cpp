	test ! -f .git/MERGE_HEAD &&
	# Merge successfully completed
	post_merge_head="$(git rev-parse HEAD)" &&
	test_must_fail git merge --abort 2>output &&
	grep -q MERGE_HEAD output &&
	test ! -f .git/MERGE_HEAD &&
	test "$post_merge_head" = "$(git rev-parse HEAD)"
'