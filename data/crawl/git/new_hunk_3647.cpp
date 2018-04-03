	check_bookmark hgrepo feature-b feature-b
'

test_expect_failure 'remote push diverged' '
	test_when_finished "rm -rf gitrepo*" &&

	git clone "hg::hgrepo" gitrepo &&

	(
	cd hgrepo &&
	hg checkout default &&
	echo bump > content &&
	hg commit -m bump
	) &&

	(
	cd gitrepo &&
	echo diverge > content &&
	git commit -a -m diverged &&
	test_expect_code 1 git push 2> error &&
	grep "^ ! \[rejected\] *master -> master (non-fast-forward)$" error
	) &&

	check_branch hgrepo default bump
'

test_done