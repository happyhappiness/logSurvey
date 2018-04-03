	git config -f .gitmodules  --remove-section submodule.subname
'

test_expect_success '--ignore-submodules=dirty suppresses submodules with modified content' '
	echo modified > sm/foo &&
	git status --ignore-submodules=dirty > output &&
	test_cmp expect output
'

test_expect_success '.gitmodules ignore=dirty suppresses submodules with modified content' '
	git config --add -f .gitmodules submodule.subname.ignore dirty &&
	git config --add -f .gitmodules submodule.subname.path sm &&
	git status > output &&
	test_cmp expect output &&
	git config -f .gitmodules  --remove-section submodule.subname
'

test_expect_success '.git/config ignore=dirty suppresses submodules with modified content' '
	git config --add -f .gitmodules submodule.subname.ignore none &&
	git config --add -f .gitmodules submodule.subname.path sm &&
	git config --add submodule.subname.ignore dirty &&
