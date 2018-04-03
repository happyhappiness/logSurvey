	cd gitrepo &&
	echo diverge > content &&
	git commit -a -m diverged &&
	check_push 1 <<-EOF
	master:non-fast-forward
	EOF
	) &&

	check_branch hgrepo default bump
