
	(
	cd gitrepo &&

	check_push 1 --all <<-EOF
	master
	good_bmark
	branches/good_branch
	new_bmark:new
	branches/new_branch:new
	bad_bmark1:non-fast-forward
	bad_bmark2:non-fast-forward
	branches/bad_branch:non-fast-forward
	EOF
	) &&

	check_branch hgrepo default one &&