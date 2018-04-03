EOF

test_expect_success 'add --tags' '
	rm -rf add-tags &&
	(
		mkdir add-tags &&
		cd add-tags &&
		git init &&
		git remote add -f --tags origin ../one &&
		git tag -l some-tag >../test/output &&
		git tag -l foobar-tag >>../test/output &&
		git config remote.origin.tagopt >>../test/output
	) &&
	test_cmp test/expect test/output
'

