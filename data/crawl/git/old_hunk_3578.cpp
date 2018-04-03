EOF

test_expect_success 'update with arguments' '

	(cd one &&
	 for b in $(git branch -r)
	 do
		git branch -r -d $b || break
	 done &&
	 git remote add manduca ../mirror &&
	 git remote add megaloprepus ../mirror &&
	 git config remotes.phobaeticus "drosophila megaloprepus" &&
	 git config remotes.titanus manduca &&
	 git remote update phobaeticus titanus &&
	 git branch -r > output &&
	 test_cmp expect output)

'

test_expect_success 'update --prune' '

	(cd one &&
	 git branch -m side2 side3) &&
	(cd test &&
	 git remote update --prune &&
	 (cd ../one && git branch -m side3 side2) &&
	 git rev-parse refs/remotes/origin/side3 &&
	 test_must_fail git rev-parse refs/remotes/origin/side2)
'

cat > one/expect << EOF
  apis/master
  apis/side
  manduca/master
