 	compare_refs local dup server dup
 '
 
+test_expect_success 'proper failure checks for fetching' '
+	(GIT_REMOTE_TESTGIT_FAILURE=1 &&
+	export GIT_REMOTE_TESTGIT_FAILURE &&
+	cd local &&
+	test_must_fail git fetch 2> error &&
+	cat error &&
+	grep -q "Error while running fast-import" error
+	)
+'
+
+test_expect_success 'proper failure checks for pushing' '
+	(GIT_REMOTE_TESTGIT_FAILURE=1 &&
+	export GIT_REMOTE_TESTGIT_FAILURE &&
+	cd local &&
+	test_must_fail git push --all 2> error &&
+	cat error &&
+	grep -q "Reading from remote helper failed" error
+	)
+'
+
 test_done
