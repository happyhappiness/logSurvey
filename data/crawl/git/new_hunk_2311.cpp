	test_cmp expected3 output
'

test_expect_success 'ls-files --others handles non-submodule .git' '
	mkdir not-a-submodule &&
	echo foo >not-a-submodule/.git &&
	git ls-files -o >output &&
	test_cmp expected1 output
'

test_expect_success SYMLINKS 'ls-files --others with symlinked submodule' '
	git init super &&
	git init sub &&