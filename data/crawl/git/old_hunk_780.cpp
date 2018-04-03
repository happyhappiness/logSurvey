}

test_expect_success 'basic usage requires no repo' '
	lines=$(git difftool -h | grep ^usage: | wc -l) &&
	test "$lines" -eq 1 &&
	# create a ceiling directory to prevent Git from finding a repo
	mkdir -p not/repo &&
	ceiling="$PWD/not" &&
	lines=$(cd not/repo &&
		GIT_CEILING_DIRECTORIES="$ceiling" git difftool -h |
		grep ^usage: | wc -l) &&
	test "$lines" -eq 1 &&
	rmdir -p not/repo
'

# Create a file on master and change it on branch