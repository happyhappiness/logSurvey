 #	output
 #	untracked
 EOF
-test_expect_success 'status submodule summary' '
+test_expect_success C_LOCALE_OUTPUT 'status submodule summary' '
 	git config status.submodulesummary 10 &&
 	git status >output &&
 	test_cmp expect output
