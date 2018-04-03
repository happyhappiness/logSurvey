	 test_must_fail git rev-parse refs/remotes/origin/side)
'

test_expect_success 'set-head --delete' '
	(cd test &&
	 git symbolic-ref refs/remotes/origin/HEAD &&
	 git remote set-head --delete origin &&
	 test_must_fail git symbolic-ref refs/remotes/origin/HEAD)
'

test_expect_success 'set-head --auto' '
	(cd test &&
	 git remote set-head --auto origin &&
	 echo refs/remotes/origin/master >expect &&
	 git symbolic-ref refs/remotes/origin/HEAD >output &&
	 test_cmp expect output
	)
'

cat >test/expect <<EOF
error: Multiple remote HEAD branches. Please choose one explicitly with:
  git remote set-head two another
  git remote set-head two master
EOF

test_expect_success 'set-head --auto fails w/multiple HEADs' '
	(cd test &&
	 test_must_fail git remote set-head --auto two >output 2>&1 &&
	test_cmp expect output)
'

cat >test/expect <<EOF
refs/remotes/origin/side2
EOF

test_expect_success 'set-head explicit' '
	(cd test &&
	 git remote set-head origin side2 &&
	 git symbolic-ref refs/remotes/origin/HEAD >output &&
	 git remote set-head origin master &&
	 test_cmp expect output)
'

cat > test/expect << EOF
Pruning origin
URL: $(pwd)/one