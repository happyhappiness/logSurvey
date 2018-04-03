	rmdir init
'

test_expect_success 'submodule deinit from subdirectory' '
	git submodule update --init &&
	git config submodule.example.foo bar &&
	mkdir -p sub &&
	(
		cd sub &&
		git submodule deinit ../init >../output
	) &&
	grep "\\.\\./init" output &&
	test -z "$(git config --get-regexp "submodule\.example\.")" &&
	test -n "$(git config --get-regexp "submodule\.example2\.")" &&
	test -f example2/.git &&
	rmdir init
'

test_expect_success 'submodule deinit . deinits all initialized submodules' '
	git submodule update --init &&
	git config submodule.example.foo bar &&
