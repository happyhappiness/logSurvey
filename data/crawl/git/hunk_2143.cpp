 EOF
 
 test_expect_success 'OPT_NUMBER_CALLBACK() works' '
-	test-parse-options -12345 > output 2> output.err &&
+	test-parse-options -12345 >output 2>output.err &&
 	test_must_be_empty output.err &&
 	test_cmp expect output
 '
 
-cat >expect <<EOF
+cat >expect <<\EOF
 boolean: 0
 integer: 0
 magnitude: 0
