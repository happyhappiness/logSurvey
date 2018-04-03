	test_cmp expect output
'

cat > expect << EOF
# On branch master
# Changed but not updated:
#   (use "git add <file>..." to update what will be committed)
#   (use "git checkout -- <file>..." to discard changes in working directory)
#
#	modified:   dir1/modified
#
# Untracked files:
#   (use "git add <file>..." to include in what will be committed)
#
#	dir1/untracked
#	dir2/modified
#	dir2/untracked
#	expect
#	output
#	untracked
no changes added to commit (use "git add" and/or "git commit -a")
EOF

test_expect_success '--ignore-submodules=untracked suppresses submodules with untracked content' '
	echo modified > sm/untracked &&
	git status --ignore-submodules=untracked > output &&
	test_cmp expect output
'

test_expect_success '--ignore-submodules=dirty suppresses submodules with untracked content' '
	git status --ignore-submodules=dirty > output &&
	test_cmp expect output
'

test_expect_success '--ignore-submodules=dirty suppresses submodules with modified content' '
	echo modified > sm/foo &&
	git status --ignore-submodules=dirty > output &&
	test_cmp expect output
'

cat > expect << EOF
# On branch master
# Changed but not updated:
#   (use "git add <file>..." to update what will be committed)
#   (use "git checkout -- <file>..." to discard changes in working directory)
#   (commit or discard the untracked or modified content in submodules)
#
#	modified:   dir1/modified
#	modified:   sm (modified content)
#
# Untracked files:
#   (use "git add <file>..." to include in what will be committed)
#
#	dir1/untracked
#	dir2/modified
#	dir2/untracked
#	expect
#	output
#	untracked
no changes added to commit (use "git add" and/or "git commit -a")
EOF

test_expect_success "--ignore-submodules=untracked doesn't suppress submodules with modified content" '
	git status --ignore-submodules=untracked > output &&
	test_cmp expect output
'

head2=$(cd sm && git commit -q -m "2nd commit" foo && git rev-parse --short=7 --verify HEAD)

cat > expect << EOF
# On branch master
# Changed but not updated:
#   (use "git add <file>..." to update what will be committed)
#   (use "git checkout -- <file>..." to discard changes in working directory)
#
#	modified:   dir1/modified
#	modified:   sm (new commits)
#
# Submodules changed but not updated:
#
# * sm $head...$head2 (1):
#   > 2nd commit
#
# Untracked files:
#   (use "git add <file>..." to include in what will be committed)
#
#	dir1/untracked
#	dir2/modified
#	dir2/untracked
#	expect
#	output
#	untracked
no changes added to commit (use "git add" and/or "git commit -a")
EOF

test_expect_success "--ignore-submodules=untracked doesn't suppress submodule summary" '
	git status --ignore-submodules=untracked > output &&
	test_cmp expect output
'

test_expect_success "--ignore-submodules=dirty doesn't suppress submodule summary" '
	git status --ignore-submodules=dirty > output &&
	test_cmp expect output
'

cat > expect << EOF
# On branch master
# Changed but not updated:
#   (use "git add <file>..." to update what will be committed)
#   (use "git checkout -- <file>..." to discard changes in working directory)
#
#	modified:   dir1/modified
#
# Untracked files:
#   (use "git add <file>..." to include in what will be committed)
#
#	dir1/untracked
#	dir2/modified
#	dir2/untracked
#	expect
#	output
#	untracked
no changes added to commit (use "git add" and/or "git commit -a")
EOF

test_expect_success "--ignore-submodules=all suppresses submodule summary" '
	git status --ignore-submodules=all > output &&
	test_cmp expect output
'

test_done
