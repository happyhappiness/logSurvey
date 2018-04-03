	git config --unset status.showUntrackedFiles
'

test_expect_success 'git commit will commit a staged but ignored submodule' '
	git config --add -f .gitmodules submodule.subname.ignore all &&
	git config --add -f .gitmodules submodule.subname.path sm &&
	git config --add submodule.subname.ignore all &&
	git status -s --ignore-submodules=dirty >output &&
	test_i18ngrep "^M. sm" output &&
	GIT_EDITOR="echo hello >>\"\$1\"" &&
	export GIT_EDITOR &&
	git commit -uno &&
	git status -s --ignore-submodules=dirty >output &&
	test_i18ngrep ! "^M. sm" output
'

test_expect_success 'git commit --dry-run will show a staged but ignored submodule' '
	git reset HEAD^ &&
	git add sm &&
	cat >expect << EOF &&
On branch master
Changes to be committed:
  (use "git reset HEAD <file>..." to unstage)

	modified:   sm

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git checkout -- <file>..." to discard changes in working directory)

	modified:   dir1/modified

Untracked files not listed (use -u option to show untracked files)
EOF
	git commit -uno --dry-run >output &&
	test_i18ncmp expect output &&
	git status -s --ignore-submodules=dirty >output &&
	test_i18ngrep "^M. sm" output
'

test_expect_failure 'git commit -m will commit a staged but ignored submodule' '
	git commit -uno -m message &&
	git status -s --ignore-submodules=dirty >output &&
	 test_i18ngrep ! "^M. sm" output &&
	git config --remove-section submodule.subname &&
	git config -f .gitmodules  --remove-section submodule.subname
'

test_done
