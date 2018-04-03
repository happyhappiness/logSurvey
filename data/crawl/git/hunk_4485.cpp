 	git config --remove-section -f .gitmodules submodule.subname
 '
 
-test_expect_success '--ignore-submodules=dirty suppresses submodules with untracked content' '
+test_expect_success C_LOCALE_OUTPUT '--ignore-submodules=dirty suppresses submodules with untracked content' '
 	git status --ignore-submodules=dirty > output &&
 	test_cmp expect output
 '
 
-test_expect_success '.gitmodules ignore=dirty suppresses submodules with untracked content' '
+test_expect_success C_LOCALE_OUTPUT '.gitmodules ignore=dirty suppresses submodules with untracked content' '
 	git config diff.ignoreSubmodules dirty &&
 	git status >output &&
 	! test -s actual &&
