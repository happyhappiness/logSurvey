	test_i18ncmp expect output
'

test_expect_success '.gitmodules ignore=all suppresses unstaged submodule summary' '
	cat > expect << EOF &&
On branch master
Changes to be committed:
  (use "git reset HEAD <file>..." to unstage)

	modified:   sm

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git checkout -- <file>..." to discard changes in working directory)

	modified:   dir1/modified

Untracked files:
  (use "git add <file>..." to include in what will be committed)

	.gitmodules
	dir1/untracked
	dir2/modified
	dir2/untracked
	expect
	output
	untracked

EOF
	git config --add -f .gitmodules submodule.subname.ignore all &&
	git config --add -f .gitmodules submodule.subname.path sm &&
	git status > output &&
	test_cmp expect output &&
	git config -f .gitmodules  --remove-section submodule.subname
'

test_expect_success '.git/config ignore=all suppresses unstaged submodule summary' '
	git config --add -f .gitmodules submodule.subname.ignore none &&
	git config --add -f .gitmodules submodule.subname.path sm &&
	git config --add submodule.subname.ignore all &&
