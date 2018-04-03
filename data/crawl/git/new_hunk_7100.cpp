	test_cmp expect output
'

test_expect_success 'status (status.showUntrackedFiles normal)' '
	git config status.showuntrackedfiles normal
	git status >output &&
	test_cmp expect output
'

cat >expect <<EOF
# On branch master
# Changes to be committed:
