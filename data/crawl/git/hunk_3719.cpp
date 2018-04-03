 	test 2 = $(grep "my sig" output | wc -l)
 '
 
-test_expect_success 'format.signature="" supresses signatures' '
+test_expect_success 'format.signature="" suppresses signatures' '
 	git config format.signature "" &&
 	git format-patch --stdout -1 >output &&
 	check_patch output &&
 	! grep "^-- \$" output
 '
 
-test_expect_success 'format-patch --no-signature supresses signatures' '
+test_expect_success 'format-patch --no-signature suppresses signatures' '
 	git config --unset-all format.signature &&
 	git format-patch --stdout --no-signature -1 >output &&
 	check_patch output &&
 	! grep "^-- \$" output
 '
 
-test_expect_success 'format-patch --signature="" supresses signatures' '
+test_expect_success 'format-patch --signature="" suppresses signatures' '
 	git format-patch --stdout --signature="" -1 >output &&
 	check_patch output &&
 	! grep "^-- \$" output
