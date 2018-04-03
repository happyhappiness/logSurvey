 test_expect_success '"git log :/a" should be ambiguous (applied both rev and worktree)' '
 	: >a &&
 	test_must_fail git log :/a 2>error &&
-	grep ambiguous error
+	test_i18ngrep ambiguous error
 '
 
 test_expect_success '"git log :/a -- " should not be ambiguous' '
