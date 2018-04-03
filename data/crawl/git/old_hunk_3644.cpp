
	(
	cd gitrepo &&
	test_expect_code 1 git push origin master \
		good_bmark bad_bmark1 bad_bmark2 new_bmark \
		branches/good_branch branches/bad_branch \
		branches/new_branch 2> error &&

	grep "^   [a-f0-9]*\.\.[a-f0-9]* *master -> master$" error &&
	grep "^   [a-f0-9]*\.\.[a-f0-9]* *good_bmark -> good_bmark$" error &&
	grep "^ \* \[new branch\] *new_bmark -> new_bmark$" error &&
	grep "^ ! \[rejected\] *bad_bmark2 -> bad_bmark2 (non-fast-forward)$" error &&
	grep "^ ! \[rejected\] *bad_bmark1 -> bad_bmark1 (non-fast-forward)$" error &&
	grep "^   [a-f0-9]*\.\.[a-f0-9]* *branches/good_branch -> branches/good_branch$" error &&
	grep "^ ! \[rejected\] *branches/bad_branch -> branches/bad_branch (non-fast-forward)$" error &&
	grep "^ \* \[new branch\] *branches/new_branch -> branches/new_branch$" error
	) &&

	check_branch hgrepo default one &&