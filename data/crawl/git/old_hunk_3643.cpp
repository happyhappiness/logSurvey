	git checkout --quiet diverge &&
	echo diverge > content &&
	git commit -a -m diverge &&
	test_expect_code 1 git push 2> error &&
	grep "^ ! \[rejected\] *diverge -> diverge (non-fast-forward)$" error
	) &&

	check_bookmark hgrepo diverge "bump bookmark"
