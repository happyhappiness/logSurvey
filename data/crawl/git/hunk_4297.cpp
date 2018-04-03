 #	output
 #	untracked
 EOF
-test_expect_success C_LOCALE_OUTPUT 'status -unormal' '
+test_expect_success 'status -unormal' '
 	git status -unormal >output &&
-	test_cmp expect output
+	test_i18ncmp expect output
 '
 
-test_expect_success C_LOCALE_OUTPUT 'status (status.showUntrackedFiles normal)' '
+test_expect_success 'status (status.showUntrackedFiles normal)' '
 	git config status.showuntrackedfiles normal
 	test_when_finished "git config --unset status.showuntrackedfiles" &&
 	git status >output &&
-	test_cmp expect output
+	test_i18ncmp expect output
 '
 
 cat >expect <<EOF
