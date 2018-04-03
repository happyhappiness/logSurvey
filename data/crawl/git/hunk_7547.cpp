 	git diff expect output
 '
 
+cat > expect.err << EOF
+error: did you mean \`--boolean\` (with two dashes ?)
+EOF
+
+test_expect_success 'detect possible typos' '
+	! test-parse-options -boolean > output 2> output.err &&
+	test ! -s output &&
+	git diff expect.err output.err
+'
+
 test_done
