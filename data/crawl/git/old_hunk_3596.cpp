	rmdir init
'

test_expect_success 'submodule deinit . deinits all initialized submodules' '
	git submodule update --init &&
	git config submodule.example.foo bar &&
