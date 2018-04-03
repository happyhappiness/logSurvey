 
 	init_vars &&
 	rm -f "$HOME/stdout" "$HOME/stderr" "$HOME/cmd" &&
-	echo git $global_args check-ignore $quiet_opt $verbose_opt $args \
+	echo git $global_args check-ignore $quiet_opt $verbose_opt $non_matching_opt $args \
 		>"$HOME/cmd" &&
+	echo "$expect_code" >"$HOME/expected-exit-code" &&
 	test_expect_code "$expect_code" \
-		git $global_args check-ignore $quiet_opt $verbose_opt $args \
+		git $global_args check-ignore $quiet_opt $verbose_opt $non_matching_opt $args \
 		>"$HOME/stdout" 2>"$HOME/stderr" &&
 	test_cmp "$HOME/expected-stdout" "$HOME/stdout" &&
 	stderr_empty_on_success "$expect_code"
 }
 
-# Runs the same code with 3 different levels of output verbosity,
+# Runs the same code with 4 different levels of output verbosity:
+#
+#   1. with -q / --quiet
+#   2. with default verbosity
+#   3. with -v / --verbose
+#   4. with -v / --verbose, *and* -n / --non-matching
+#
 # expecting success each time.  Takes advantage of the fact that
 # check-ignore --verbose output is the same as normal output except
 # for the extra first column.
 #
 # Arguments:
 #   - (optional) prereqs for this test, e.g. 'SYMLINKS'
 #   - test name
-#   - output to expect from -v / --verbose mode
+#   - output to expect from the fourth verbosity mode (the output
+#     from the other verbosity modes is automatically inferred
+#     from this value)
 #   - code to run (should invoke test_check_ignore)
 test_expect_success_multi () {
 	prereq=
