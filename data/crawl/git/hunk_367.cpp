 	git config -f .gitmodules  --remove-section submodule.subname
 '
 
+test_expect_success '"No commits yet" should be noted in status output' '
+	git checkout --orphan empty-branch-1 &&
+	git status >output &&
+	test_i18ngrep "No commits yet" output
+'
+
+test_expect_success '"No commits yet" should not be noted in status output' '
+	git checkout --orphan empty-branch-2 &&
+	test_commit test-commit-1 &&
+	git status >output &&
+	test_i18ngrep ! "No commits yet" output
+'
+
+test_expect_success '"Initial commit" should be noted in commit template' '
+	git checkout --orphan empty-branch-3 &&
+	touch to_be_committed_1 &&
+	git add to_be_committed_1 &&
+	git commit --dry-run >output &&
+	test_i18ngrep "Initial commit" output
+'
+
+test_expect_success '"Initial commit" should not be noted in commit template' '
+	git checkout --orphan empty-branch-4 &&
+	test_commit test-commit-2 &&
+	touch to_be_committed_2 &&
+	git add to_be_committed_2 &&
+	git commit --dry-run >output &&
+	test_i18ngrep ! "Initial commit" output
+'
+
 test_done
