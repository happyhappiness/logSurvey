	test_cmp expected3 output
'

test_expect_success SYMLINKS 'ls-files --others with symlinked submodule' '
	git init super &&
	git init sub &&