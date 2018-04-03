#	output
#	untracked
EOF
test_expect_success 'status -uall' '
	git status -uall >output &&
	test_cmp expect output
'
test_expect_success 'status (status.showUntrackedFiles all)' '
	git config status.showuntrackedfiles all
	git status >output &&
	rm -rf dir3 &&
	git config --unset status.showuntrackedfiles &&
	test_cmp expect output
'

cat >expect <<EOF
 M dir1/modified
A  dir2/added
