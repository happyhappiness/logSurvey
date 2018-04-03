 #	output
 #	untracked
 EOF
-test_expect_success 'status -uall' '
+test_expect_success C_LOCALE_OUTPUT 'status -uall' '
 	git status -uall >output &&
 	test_cmp expect output
 '
-test_expect_success 'status (status.showUntrackedFiles all)' '
+test_expect_success C_LOCALE_OUTPUT 'status (status.showUntrackedFiles all)' '
 	git config status.showuntrackedfiles all
+	test_when_finished "git config --unset status.showuntrackedfiles" &&
 	git status >output &&
-	rm -rf dir3 &&
-	git config --unset status.showuntrackedfiles &&
 	test_cmp expect output
 '
 
+test_expect_success 'teardown dir3' '
+	rm -rf dir3
+'
+
 cat >expect <<EOF
  M dir1/modified
 A  dir2/added
