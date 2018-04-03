#
# Untracked files not listed (use -u option to show untracked files)
EOF
test_expect_success 'status -uno' '
	mkdir dir3 &&
	: >dir3/untracked1 &&
	: >dir3/untracked2 &&
	git status -uno >output &&
	test_cmp expect output
'

test_expect_success 'status (status.showUntrackedFiles no)' '
	git config status.showuntrackedfiles no
	git status >output &&
	test_cmp expect output
'
