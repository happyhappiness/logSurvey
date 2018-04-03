 pre_merge_head="$(git rev-parse HEAD)"
 
 test_expect_success 'fails without MERGE_HEAD (unstarted merge)' '
-	test_must_fail git merge --abort 2>output &&
-	grep -q MERGE_HEAD output &&
+	test_must_fail git merge --abort 2>output
+'
+
+test_expect_success C_LOCALE_OUTPUT 'fails without MERGE_HEAD (unstarted merge): fatal output' '
+	grep -q MERGE_HEAD output
+'
+
+test_expect_success 'fails without MERGE_HEAD (unstarted merge): .git/MERGE_HEAD sanity' '
 	test ! -f .git/MERGE_HEAD &&
 	test "$pre_merge_head" = "$(git rev-parse HEAD)"
 '
