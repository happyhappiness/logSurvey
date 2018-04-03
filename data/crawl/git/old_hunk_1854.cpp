		cd sub &&
		git submodule deinit ../init >../output
	) &&
	grep "\\.\\./init" output &&
	test -z "$(git config --get-regexp "submodule\.example\.")" &&
	test -n "$(git config --get-regexp "submodule\.example2\.")" &&
	test -f example2/.git &&
