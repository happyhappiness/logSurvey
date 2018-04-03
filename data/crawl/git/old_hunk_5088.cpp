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
