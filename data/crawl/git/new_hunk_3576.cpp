EOF

test_expect_success 'add --no-tags' '
	rm -rf add-tags &&
	(
		mkdir add-no-tags &&
		cd add-no-tags &&
		git init &&
		git remote add -f --no-tags origin ../one &&
		git tag -l some-tag >../test/output &&
		git tag -l foobar-tag >../test/output &&
		git config remote.origin.tagopt >>../test/output
	) &&
	(
		cd one &&
		git tag -d some-tag foobar-tag
	) &&
	test_cmp test/expect test/output
'

test_expect_success 'reject --no-no-tags' '
	(
		cd add-no-tags &&
		test_must_fail git remote add -f --no-no-tags neworigin ../one
	)
'

cat >one/expect <<\EOF
  apis/master
  apis/side
  drosophila/another
