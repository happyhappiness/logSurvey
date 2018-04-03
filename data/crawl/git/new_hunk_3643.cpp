	git checkout --quiet diverge &&
	echo diverge > content &&
	git commit -a -m diverge &&
	check_push 1 <<-EOF
	diverge:non-fast-forward
	EOF
	) &&

	check_bookmark hgrepo diverge "bump bookmark"
