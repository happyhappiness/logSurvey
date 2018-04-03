
test_expect_success 'basic usage requires no repo' '
	test_expect_code 129 git difftool -h >output &&
	grep ^usage: output &&
	# create a ceiling directory to prevent Git from finding a repo
	mkdir -p not/repo &&
	test_when_finished rm -r not &&
	test_expect_code 129 \
	env GIT_CEILING_DIRECTORIES="$(pwd)/not" \
	git -C not/repo difftool -h >output &&
	grep ^usage: output
'

# Create a file on master and change it on branch