 	test_cmp expect output
 '
 
-cat > expect.err << EOF
+cat > typo.err << EOF
 error: did you mean \`--boolean\` (with two dashes ?)
 EOF
 
 test_expect_success 'detect possible typos' '
-	! test-parse-options -boolean > output 2> output.err &&
+	test_must_fail test-parse-options -boolean > output 2> output.err &&
 	test ! -s output &&
-	test_cmp expect.err output.err
+	test_cmp typo.err output.err
 '
 
 cat > expect <<EOF
 boolean: 0
 integer: 0
 string: (not set)
+abbrev: 7
+verbose: 0
+quiet: no
+dry run: no
 arg 00: --quux
 EOF
 
