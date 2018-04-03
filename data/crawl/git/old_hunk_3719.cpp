	test 2 = $(grep "my sig" output | wc -l)
'

test_expect_success 'format.signature="" supresses signatures' '
	git config format.signature "" &&
	git format-patch --stdout -1 >output &&
	check_patch output &&
	! grep "^-- \$" output
'

test_expect_success 'format-patch --no-signature supresses signatures' '
	git config --unset-all format.signature &&
	git format-patch --stdout --no-signature -1 >output &&
	check_patch output &&
	! grep "^-- \$" output
'

test_expect_success 'format-patch --signature="" supresses signatures' '
	git format-patch --stdout --signature="" -1 >output &&
	check_patch output &&
	! grep "^-- \$" output
