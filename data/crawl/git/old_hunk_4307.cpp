#	untracked
EOF

test_expect_success C_LOCALE_OUTPUT '--ignore-submodules=untracked suppresses submodules with untracked content' '
	echo modified > sm/untracked &&
	git status --ignore-submodules=untracked > output &&
	test_cmp expect output
'

test_expect_success C_LOCALE_OUTPUT '.gitmodules ignore=untracked suppresses submodules with untracked content' '
	git config diff.ignoreSubmodules dirty &&
	git status >output &&
	test_cmp expect output &&
	git config --add -f .gitmodules submodule.subname.ignore untracked &&
	git config --add -f .gitmodules submodule.subname.path sm &&
	git status > output &&
	test_cmp expect output &&
	git config -f .gitmodules  --remove-section submodule.subname &&
	git config --unset diff.ignoreSubmodules
'

test_expect_success C_LOCALE_OUTPUT '.git/config ignore=untracked suppresses submodules with untracked content' '
	git config --add -f .gitmodules submodule.subname.ignore none &&
	git config --add -f .gitmodules submodule.subname.path sm &&
	git config --add submodule.subname.ignore untracked &&
	git config --add submodule.subname.path sm &&
	git status > output &&
	test_cmp expect output &&
	git config --remove-section submodule.subname &&
	git config --remove-section -f .gitmodules submodule.subname
'

test_expect_success C_LOCALE_OUTPUT '--ignore-submodules=dirty suppresses submodules with untracked content' '
	git status --ignore-submodules=dirty > output &&
	test_cmp expect output
'

test_expect_success C_LOCALE_OUTPUT '.gitmodules ignore=dirty suppresses submodules with untracked content' '
	git config diff.ignoreSubmodules dirty &&
	git status >output &&
	! test -s actual &&
	git config --add -f .gitmodules submodule.subname.ignore dirty &&
	git config --add -f .gitmodules submodule.subname.path sm &&
	git status > output &&
	test_cmp expect output &&
	git config -f .gitmodules  --remove-section submodule.subname &&
	git config --unset diff.ignoreSubmodules
'

test_expect_success C_LOCALE_OUTPUT '.git/config ignore=dirty suppresses submodules with untracked content' '
	git config --add -f .gitmodules submodule.subname.ignore none &&
	git config --add -f .gitmodules submodule.subname.path sm &&
	git config --add submodule.subname.ignore dirty &&
	git config --add submodule.subname.path sm &&
	git status > output &&
	test_cmp expect output &&
	git config --remove-section submodule.subname &&
	git config -f .gitmodules  --remove-section submodule.subname
'

test_expect_success C_LOCALE_OUTPUT '--ignore-submodules=dirty suppresses submodules with modified content' '
	echo modified > sm/foo &&
	git status --ignore-submodules=dirty > output &&
	test_cmp expect output
'

test_expect_success C_LOCALE_OUTPUT '.gitmodules ignore=dirty suppresses submodules with modified content' '
	git config --add -f .gitmodules submodule.subname.ignore dirty &&
	git config --add -f .gitmodules submodule.subname.path sm &&
	git status > output &&
	test_cmp expect output &&
	git config -f .gitmodules  --remove-section submodule.subname
'

test_expect_success C_LOCALE_OUTPUT '.git/config ignore=dirty suppresses submodules with modified content' '
	git config --add -f .gitmodules submodule.subname.ignore none &&
	git config --add -f .gitmodules submodule.subname.path sm &&
	git config --add submodule.subname.ignore dirty &&
	git config --add submodule.subname.path sm &&
	git status > output &&
	test_cmp expect output &&
	git config --remove-section submodule.subname &&
	git config -f .gitmodules  --remove-section submodule.subname
'
