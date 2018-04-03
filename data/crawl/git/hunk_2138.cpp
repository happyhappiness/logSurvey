 EOF
 
 test_expect_success 'keep some options as arguments' '
-	test-parse-options --quux > output 2> output.err &&
+	test-parse-options --quux >output 2>output.err &&
 	test_must_be_empty output.err &&
-        test_cmp expect output
+	test_cmp expect output
 '
 
-cat > expect <<EOF
+cat >expect <<\EOF
 boolean: 0
 integer: 0
 magnitude: 0
