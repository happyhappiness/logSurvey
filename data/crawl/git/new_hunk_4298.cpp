#	output
#	untracked
EOF
test_expect_success 'status -uall' '
	git status -uall >output &&
	test_i18ncmp expect output
'

test_expect_success 'status (status.showUntrackedFiles all)' '
	git config status.showuntrackedfiles all
	test_when_finished "git config --unset status.showuntrackedfiles" &&
	git status >output &&
	test_i18ncmp expect output
'

test_expect_success 'teardown dir3' '
