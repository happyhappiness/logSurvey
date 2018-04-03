 	! grep "Writing objects" err
 '
 
+test_expect_success TTY 'quiet push' '
+	ensure_fresh_upstream &&
+
+	test_terminal git push --quiet --no-progress upstream master 2>&1 | tee output &&
+	test_cmp /dev/null output
+'
+
 test_done
