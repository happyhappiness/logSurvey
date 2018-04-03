	check_bookmark hgrepo feature-c feature-c
'

# cleanup previous stuff
rm -rf hgrepo

test_expect_failure 'remote big push' '
	test_when_finished "rm -rf hgrepo gitrepo*" &&

	(
	hg init hgrepo &&
	cd hgrepo &&
	echo zero > content &&
	hg add content &&
	hg commit -m zero &&
	hg bookmark bad_bmark1 &&
	echo one > content &&
	hg commit -m one &&
	hg bookmark bad_bmark2 &&
	hg bookmark good_bmark &&
	hg bookmark -i good_bmark &&
	hg -q branch good_branch &&
	echo "good branch" > content &&
	hg commit -m "good branch" &&
	hg -q branch bad_branch &&
	echo "bad branch" > content &&
	hg commit -m "bad branch"
	) &&

	git clone "hg::hgrepo" gitrepo &&

	(
	cd gitrepo &&
	echo two > content &&
	git commit -q -a -m two &&

	git checkout -q good_bmark &&
	echo three > content &&
	git commit -q -a -m three &&

	git checkout -q bad_bmark1 &&
	git reset --hard HEAD^ &&
	echo four > content &&
	git commit -q -a -m four &&

	git checkout -q bad_bmark2 &&
	git reset --hard HEAD^ &&
	echo five > content &&
	git commit -q -a -m five &&

	git checkout -q -b new_bmark master &&
	echo six > content &&
	git commit -q -a -m six &&

	git checkout -q branches/good_branch &&
	echo seven > content &&
	git commit -q -a -m seven &&
	echo eight > content &&
	git commit -q -a -m eight &&

	git checkout -q branches/bad_branch &&
	git reset --hard HEAD^ &&
	echo nine > content &&
	git commit -q -a -m nine &&

	git checkout -q -b branches/new_branch master &&
	echo ten > content &&
	git commit -q -a -m ten &&

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
	check_branch hgrepo good_branch "good branch" &&
	check_branch hgrepo bad_branch "bad branch" &&
	check_branch hgrepo new_branch '' &&
	check_bookmark hgrepo good_bmark one &&
	check_bookmark hgrepo bad_bmark1 one &&
	check_bookmark hgrepo bad_bmark2 one &&
	check_bookmark hgrepo new_bmark ''
'

test_done