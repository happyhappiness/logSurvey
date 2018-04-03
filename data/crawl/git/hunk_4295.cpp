 #
 # Untracked files not listed (use -u option to show untracked files)
 EOF
-test_expect_success C_LOCALE_OUTPUT 'status -uno' '
+test_expect_success 'status -uno' '
 	git status -uno >output &&
-	test_cmp expect output
+	test_i18ncmp expect output
 '
 
-test_expect_success C_LOCALE_OUTPUT 'status (status.showUntrackedFiles no)' '
+test_expect_success 'status (status.showUntrackedFiles no)' '
 	git config status.showuntrackedfiles no
 	test_when_finished "git config --unset status.showuntrackedfiles" &&
 	git status >output &&
-	test_cmp expect output
+	test_i18ncmp expect output
 '
 
 cat >expect <<EOF
