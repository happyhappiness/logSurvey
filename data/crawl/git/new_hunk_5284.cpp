	EOF
'

test_expect_success 'setup .git file for sub' '
	(cd sub &&
	 rm -f new-file
	 REAL="$(pwd)/../.real" &&
	 mv .git "$REAL"
	 echo "gitdir: $REAL" >.git) &&
	 echo .real >>.gitignore &&
	 git commit -m "added .real to .gitignore" .gitignore
'

test_expect_success 'status with added file in modified submodule with .git file' '
	(cd sub && git reset --hard && echo >foo && git add foo) &&
	git status >output &&
	grep "modified:   sub (new commits, modified content)" output
'

test_expect_success 'rm submodule contents' '
	rm -rf sub/* sub/.git
'