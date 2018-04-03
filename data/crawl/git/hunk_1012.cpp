 	test_cmp typo.err output.err
 '
 
-cat >expect <<\EOF
-boolean: 0
-integer: 0
-magnitude: 0
-timestamp: 0
-string: (not set)
-abbrev: 7
-verbose: -1
-quiet: 0
-dry run: no
-file: (not set)
-arg 00: --quux
-EOF
-
 test_expect_success 'keep some options as arguments' '
-	test-parse-options --quux >output 2>output.err &&
-	test_must_be_empty output.err &&
-	test_cmp expect output
+	test-parse-options --expect="arg 00: --quux" --quux
 '
 
 cat >expect <<\EOF
