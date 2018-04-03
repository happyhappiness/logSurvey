	 test "$detected" = xCIT'

test_expect_success 'apply detecting corrupt patch correctly' \
	'git diff --binary | sed -e 's/-CIT/xCIT/' >broken &&
	 if git apply --stat --summary broken 2>detected
	 then
		echo unhappy - should have detected an error
		(exit 1)
