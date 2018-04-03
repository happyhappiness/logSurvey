	test_cmp expect actual
'

test_expect_success '--porcelain detects first non-blank line as subject' '
	(
		GIT_INDEX_FILE=.git/tmp-index &&
		export GIT_INDEX_FILE &&
		echo "This is it" >single-file &&
		git add single-file &&
		tree=$(git write-tree) &&
		commit=$(printf "%s\n%s\n%s\n\n\n  \noneline\n\nbody\n" \
			"tree $tree" \
			"author A <a@b.c> 123456789 +0000" \
			"committer C <c@d.e> 123456789 +0000" |
		git hash-object -w -t commit --stdin) &&
		git blame --porcelain $commit -- single-file >output &&
		grep "^summary oneline$" output
	)
'

test_done