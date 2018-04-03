 #	output
 #	untracked
 EOF
-test_expect_success 'status submodule summary is disabled by default' '
+test_expect_success C_LOCALE_OUTPUT 'status submodule summary is disabled by default' '
 	git status >output &&
 	test_cmp expect output
 '
 
 # we expect the same as the previous test
-test_expect_success 'status --untracked-files=all does not show submodule' '
+test_expect_success C_LOCALE_OUTPUT 'status --untracked-files=all does not show submodule' '
 	git status --untracked-files=all >output &&
 	test_cmp expect output
 '
